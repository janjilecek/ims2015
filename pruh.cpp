#include "pruh.h"

double pruh::seconds() const
{
    return m_seconds;
}

void pruh::setSeconds(double seconds)
{
    m_seconds = seconds;
}

semafor *pruh::pSemafor() const
{
    return m_semafor;
}

int pruh::counter() const
{
    return m_counter;
}

void pruh::setCounter(int counter)
{
    m_counter = counter;
}

Facility& pruh::getF()
{
    return f;
}

dayTimer *pruh::getDayTimer() const
{
    return m_dayTimer;
}

double pruh::currentSpawnTime()
{

        Print("spawn time for ");
        Print(m_nameOfArm.c_str());
        Print(" is ");
        Print(this->getDayTimer()->getCurrentTime());
        Print("\n");
        return this->getDayTimer()->getCurrentTime();
}



Histogram& pruh::getTabulka()
{
    return tabulka;
}

pruh::pruh( semafor *s, laneDir dirOfLane, dayTimer* d, const std::string nameOfArm): m_counter(0), m_dirOfLane(dirOfLane),
    m_dayTimer(d), m_nameOfArm(nameOfArm),
    m_semafor(s), m_generator(new generator(this)),
    f(m_nameOfArm.c_str()), tabulka(m_nameOfArm.c_str(), 0, HOURLENGTH, HOURS)
{
    m_generator->Activate();
}


int dayTimer::getCurrentTime() const
{
    return m_currentTime;
}

float dayTimer::calculateLoad(float former, float latter)
{
    m_loadCurrent += ((latter - former)/m_timePortion);
    if (m_loadCurrent <= 0) m_loadCurrent = 0.05; // ochrana proti chodu do minulosti a zastaveni
    return m_loadCurrent;
}

/*dayTimer::dayTimer(dayTime *d, int seconds) : m_dayTime(d),

    m_currentTime(seconds),
    m_currentHour(0),
    m_loadNormalTime(seconds),
    m_timePortion(4),
    m_loadCurrent(d->s0e4)

{
    //m_loadCurrent = m_dayTime->s0e4;
    //m_currentHour = 0;
    //m_loadNormalTime = m_dayTime->normalLoadTime;
    //m_timePortion = 4.0;
    Activate(Time);
}*/

/*dayTimer::dayTimer(dayTime d) : m_dayTime(d), m_currentHour(0), m_timePortion(4)
{
    m_loadCurrent = m_dayTime.s0e4;
    m_loadNormalTime = m_dayTime.normalLoadTime;
    Activate(Time);
}*/

dayTimer::dayTimer(int currentHour, float loadMorning, float loadAfternoon, float loadNight, float loadNormalTime, float loadExtremeLow, float loadExtremeHigh) :
    m_currentHour(currentHour), m_loadMorning(loadMorning), m_loadAfternoon(loadAfternoon), m_loadNight(loadNight),
    m_loadNormalTime(loadNormalTime), m_loadExtremeLow(loadExtremeLow), m_loadExtremeHigh(loadExtremeHigh), m_timePortion(8.0)
{
    m_loadCurrent = m_loadNight;
    Activate(Time);
}

void dayTimer::Behavior()
{
    m_currentHour = (m_currentHour+1)%24;
    if (m_currentHour > 0 && m_currentHour <= 8)
    {
        calculateLoad(m_loadNight, m_loadMorning);
    }
    else if (m_currentHour > 8 && m_currentHour <= 16)
    {
        calculateLoad(m_loadMorning, m_loadAfternoon);
    }
    else
    {
        calculateLoad(m_loadAfternoon, m_loadNight);
    }
    /*if (m_currentHour >= 0 && m_currentHour <= 4) calculateLoad(m_dayTime->s0e4, m_dayTime->s4e8);
    else if (m_currentHour > 4 && m_currentHour <= 8) calculateLoad(m_dayTime->s4e8, m_dayTime->s8e12);
    else if (m_currentHour > 8 && m_currentHour <= 12) calculateLoad(m_dayTime->s8e12, m_dayTime->s12e16);
    else if (m_currentHour > 12 && m_currentHour <= 16) calculateLoad(m_dayTime->s12e16, m_dayTime->s16e20);
    else if (m_currentHour > 16 && m_currentHour <= 20) calculateLoad(m_dayTime->s16e20, m_dayTime->s20e0);
    else calculateLoad(m_dayTime->s20e0, m_dayTime->s0e4);*/

    m_currentTime = m_loadNormalTime / m_loadCurrent;
    Activate(Time + HOURLENGTH); // kazdou hodinu
}

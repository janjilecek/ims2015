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

pruh::pruh(semafor *s, double seconds, laneDir dirOfLane, dayTimer* d, const std::string nameOfArm): m_counter(0), m_dirOfLane(dirOfLane),
    m_dayTimer(d), m_nameOfArm(nameOfArm),
    m_semafor(s), m_seconds(seconds), m_generator(new generator(this)),
    f(m_nameOfArm.c_str()), tabulka(m_nameOfArm.c_str(), 0, HOURLENGTH, 24)
{
    m_generator->Activate();
}


dayTime dayTimer::getTimeOfDay() const
{
    return m_timeOfDay;
}

int dayTimer::getCurrentTime() const
{
    return m_currentTime;
}

float dayTimer::calculateLoad(float former, float latter)
{
    if (m_loadCurrent < latter)
    {
        m_loadCurrent += (fabs(latter - former)/m_timePortion);
    }
    else if (m_loadCurrent > latter)
    {
        m_loadCurrent -= (fabs(latter - former)/m_timePortion);
    }
    if (m_loadCurrent <= 0) m_loadCurrent = 0.05; // ochrana proti chodu do minulosti a zastaveni
    return m_loadCurrent;
}

dayTimer::    dayTimer(int currentHour, float loadMorning, float loadAfternoon, float loadNight, float loadNormalTime, float loadExtremeLow, float loadExtremeHigh) :
    m_currentHour(currentHour), m_loadMorning(loadMorning), m_loadAfternoon(loadAfternoon), m_loadNight(loadNight),
    m_loadNormalTime(loadNormalTime), m_loadExtremeLow(loadExtremeLow), m_loadExtremeHigh(loadExtremeHigh), m_timePortion(8.0)
{
    m_timeOfDay = MORNING;
    m_loadCurrent = m_loadMorning;
    Activate(Time);
}

void dayTimer::Behavior()
{
    m_currentHour = (m_currentHour+1)%24;
    if (m_currentHour > 0 && m_currentHour <= 8)
    {
        calculateLoad(m_loadMorning, m_loadAfternoon);
    }
    else if (m_currentHour > 8 && m_currentHour <= 16)
    {
        calculateLoad(m_loadAfternoon, m_loadNight);
    }
    else
    {
        calculateLoad(m_loadNight, m_loadMorning);
    }
    m_currentTime = m_loadNormalTime * m_loadCurrent;
    Activate(Time + 3600); // kazdou hodinu
}

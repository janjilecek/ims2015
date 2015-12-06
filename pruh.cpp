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

   /* if (m_loadCurrent < latter)
   {
           m_loadCurrent += (fabs(latter - former)/m_timePortion);
       }
       else if (m_loadCurrent > latter)
       {
           m_loadCurrent -= (fabs(latter - former)/m_timePortion);
   }*/
    if (m_loadCurrent <= 0) m_loadCurrent = 0.05; // ochrana proti chodu do minulosti a zastaveni
    return m_loadCurrent;
}

dayTimer::dayTimer(float loadNormalTime) :
    m_dayTime(0.1,  // 0-4
              0.2,  // 4-8
              1.5,  // 8-12
              1.0,    // 12-16
              3.0,  // 16-20
              0.4,  // 20-24
              0.1,  // lowEx
              2),   // highEx
    m_currentHour(0),
    m_loadNormalTime(loadNormalTime),
    m_timePortion(4.0)
{
    m_loadCurrent = m_dayTime.s0e4;
    Activate(Time);
}

void dayTimer::Behavior()
{
    m_currentHour = (m_currentHour+1)%24;
    if (m_currentHour >= 0 && m_currentHour <= 4) calculateLoad(m_dayTime.s0e4, m_dayTime.s4e8);
    else if (m_currentHour > 4 && m_currentHour <= 8) calculateLoad(m_dayTime.s4e8, m_dayTime.s8e12);
    else if (m_currentHour > 8 && m_currentHour <= 12) calculateLoad(m_dayTime.s8e12, m_dayTime.s12e16);
    else if (m_currentHour > 12 && m_currentHour <= 16) calculateLoad(m_dayTime.s12e16, m_dayTime.s16e20);
    else if (m_currentHour > 16 && m_currentHour <= 20) calculateLoad(m_dayTime.s16e20, m_dayTime.s20e0);
    else calculateLoad(m_dayTime.s20e0, m_dayTime.s0e4);

    m_currentTime = m_loadNormalTime / m_loadCurrent;
    Activate(Time + HOURLENGTH); // kazdou hodinu
}

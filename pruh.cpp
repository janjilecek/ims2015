#include "pruh.h"

int DayTimer::simHours = 24;
float DayTimer::multiplier = 1;
double Pruh::seconds() const
{
    return m_seconds;
}

void Pruh::setSeconds(double seconds)
{
    m_seconds = seconds;
}

int Pruh::counter() const
{
    return m_counter;
}

void Pruh::setCounter(int counter)
{
    m_counter = counter;
}

Facility& Pruh::getF()
{
    return f;
}

DayTimer *Pruh::getDayTimer() const
{
    return m_dayTimer;
}

Histogram& Pruh::getTabulka()
{
    return tabulka;
}

OutputGnuplot &Pruh::getPlt()
{
    return plt;
}


Pruh::Pruh(armName namearm, DayTimer* d, const std::string nameOfArm): m_counter(0),
    m_dayTimer(d), m_nameOfArm(nameOfArm),
    m_generator(new Generator(this)),
    f(m_nameOfArm.c_str()), tabulka(m_nameOfArm.c_str(), 0, HOURLENGTH, DayTimer::simHours),
    plt(m_nameOfArm.c_str(), 0, HOURLENGTH, DayTimer::simHours, DayTimer::simHours)
{
    switch (namearm)
    {
        case HORNI: m_dayTimer->getSem().setPassable(false); break;
        case PRAVE: m_dayTimer->getSem().setPassable(true); break;
        case DOLNI: m_dayTimer->getSem().setPassable(false); break;
        case LEVE: m_dayTimer->getSem().setPassable(true); break;
    }
    multiplier = DayTimer::multiplier;
    //m_generator->Activate();
}

Pruh* Pruh::setTiming(float s0e4, float s8e12, float s16e20)
{
    getDayTimer()->getDayTime().s0e4 = s0e4;
    getDayTimer()->getDayTime().s8e12 = s8e12;
    getDayTimer()->getDayTime().s16e20 = s16e20;
    if(getDayTimer()->getCurrentHour() == 8) // high extreme
    {
        getDayTimer()->setLoadCurrent(s8e12);
    }
    else if (getDayTimer()->getCurrentHour() == 12) // normal
    {
        getDayTimer()->setLoadCurrent(1);
    }
    else if (getDayTimer()->getCurrentHour() == 16) // high extreme
    {
        getDayTimer()->setLoadCurrent(s16e20);
    }
    else
    {
        getDayTimer()->setLoadCurrent(s0e4);
    }

    getDayTimer()->getDayTime().s0e4 *= multiplier; // for experiments
    getDayTimer()->getDayTime().s4e8 *= multiplier;
    getDayTimer()->getDayTime().s8e12 *= multiplier;
    getDayTimer()->getDayTime().s12e16 *= multiplier;
    getDayTimer()->getDayTime().s16e20 *= multiplier;
    getDayTimer()->getDayTime().s20e0 *= multiplier;
    m_dayTimer->Activate(Time);
    m_generator->Activate(Time);
    return this;
}


int DayTimer::getCurrentTime() const
{
    return m_currentTime;
}

Semafor &DayTimer::getSem()
{
    return m_sem;
}

dayTime &DayTimer::getDayTime()
{
    return m_dayTime;
}

int &DayTimer::getCurrentHour()
{
    return m_currentHour;
}

void DayTimer::setLoadCurrent(float loadCurrent)
{
    m_loadCurrent = loadCurrent;
}

float DayTimer::calculateLoad(float former, float latter)
{
    m_loadCurrent += ((latter - former)/m_timePortion);
    if (m_loadCurrent <= 0) m_loadCurrent = 0.05; // ochrana proti chodu do minulosti a zastaveni
    if (m_simulateHours == 1) m_loadCurrent = former; // simulace pouze hodinu
    return m_loadCurrent;
}

DayTimer::DayTimer(float loadNormalTime, int simulateHours, int startHour) :
    m_dayTime(0.145,  // 0-4
              0.529,  // 4-8
              0.913,  // 8-12
              1.0,  // 12-16
              1.099,  // 16-20
              0.622,  // 20-24
              0.1,  // lowEx
              2),   // highEx
    m_currentHour(startHour),
    m_loadNormalTime(loadNormalTime),
    m_simulateHours(simulateHours),
    m_sem(),
    m_timePortion(4.0)
{
    m_loadCurrent = m_dayTime.s0e4;
    DayTimer::simHours = simulateHours;
    //Activate(Time);
}

void DayTimer::Behavior()
{
    m_currentHour = (m_currentHour+1)%24;

    if (m_currentHour <= 5 && m_currentHour >= 22) // v noci jsou semafory vypnute, ridici ale musi zpomalit a rozhlednout se
    {
        m_sem.setSecondsGreen(1);
        m_sem.setSecondsRed(1);
    }
    else
    {
        m_sem.setSecondsGreen(20);
        m_sem.setSecondsRed(25);
    }

    if (m_currentHour >= 0 && m_currentHour <= 4) calculateLoad(m_dayTime.s0e4, m_dayTime.s4e8);
    else if (m_currentHour > 4 && m_currentHour <= 8) calculateLoad(m_dayTime.s4e8, m_dayTime.s8e12);
    else if (m_currentHour > 8 && m_currentHour <= 12) calculateLoad(m_dayTime.s8e12, m_dayTime.s12e16);
    else if (m_currentHour > 12 && m_currentHour <= 16) calculateLoad(m_dayTime.s12e16, m_dayTime.s16e20);
    else if (m_currentHour > 16 && m_currentHour <= 20) calculateLoad(m_dayTime.s16e20, m_dayTime.s20e0);
    else calculateLoad(m_dayTime.s20e0, m_dayTime.s0e4);

    m_currentTime = m_loadNormalTime / m_loadCurrent;
    Activate(Time + HOURLENGTH); // kazdou hodinu
}

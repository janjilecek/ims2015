#include "krizovatka.h"

krizovatka::krizovatka()
{
    for (int i = 0; i < 1; ++i) //sprav zpet na 4
    {
        rameno r((armName)i);
        ramena.push_back(r);
    }
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

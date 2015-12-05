#ifndef KRIZOVATKA_H
#define KRIZOVATKA_H
#include "rameno.h"
#include <simlib.h>
#include <iostream>
#include <vector>
#include <cmath>

enum dayTime
{
    MORNING,
    AFTERNOON,
    NIGHT
};

class dayTimer : public Event
{
private:
    dayTime m_timeOfDay;
    int m_currentTime;
    int m_currentHour;
    float m_loadMorning;
    float m_loadAfternoon;
    float m_loadNight;
    float m_loadNormalTime;
    float m_loadExtremeLow;
    float m_loadExtremeHigh;
    float m_loadCurrent;
    float m_timePortion;
    float calculateLoad(float former, float latter);
public:
    dayTimer(int currentHour, float loadMorning, float loadAfternoon, float loadNight, float loadNormalTime, float loadExtremeLow, float loadExtremeHigh);
    void Behavior();
    dayTime getTimeOfDay() const;
    int getCurrentTime() const;
};

class krizovatka
{
private:
    std::vector<rameno> ramena;
public:
    krizovatka();
};



#endif // KRIZOVATKA_H

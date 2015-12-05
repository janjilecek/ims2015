#ifndef PRUH_H
#define PRUH_H
#include <simlib.h>
#include "semafor.h"
#include "generator.h"
#include <cmath>
#include <string>

#define HOURLENGTH 3600
#define HOURS 24

class generator;
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


enum laneDir
{
    ROVNE,
    DOPRAVA,
    DOLEVA
};

class pruh
{
private:
    int m_counter;
    laneDir m_dirOfLane;
    dayTimer* m_dayTimer;
    const std::string m_nameOfArm;
    semafor *m_semafor;
    double m_seconds;
    generator* m_generator;
    Facility f;
    Histogram tabulka;
public:
    pruh(semafor *s, double seconds, laneDir dirOfLane, dayTimer* d, const std::string nameOfArm);
    double seconds() const;
    void setSeconds(double seconds);

    semafor *pSemafor() const;
    int counter() const;
    void setCounter(int counter);
    Facility& getF();
    dayTimer *getDayTimer() const;
    double currentSpawnTime();
    Histogram& getTabulka();
};

#endif // PRUH_H

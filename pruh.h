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
struct dayTime
{
    float s0e4;
    float s4e8;
    float s8e12;
    float s12e16;
    float s16e20;
    float s20e0;
    float lowExtremeLoad;
    float highExtremeLoad;
    dayTime(float _s0e4, float _s4e8, float _s8e12, float _s12e16, float _s16e20, float _s20e0, float _lowExtreme, float _highExtreme) :
        s0e4(_s0e4), s4e8(_s4e8), s8e12(_s8e12), s12e16(_s12e16), s16e20(_s16e20), s20e0(_s20e0),
        lowExtremeLoad(_lowExtreme), highExtremeLoad(_highExtreme)
    {}
};

class dayTimer : public Event
{
private:
    dayTime* m_dayTime;
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
    float m_passIntersectionMin;
    float m_passIntersectionMax;
    float calculateLoad(float former, float latter);
public:
    //dayTimer(dayTime* d, int seconds);
    dayTimer(int currentHour, float loadMorning, float loadAfternoon, float loadNight, float loadNormalTime, float loadExtremeLow, float loadExtremeHigh);
    void Behavior();
    int getCurrentTime() const;
    ~dayTimer()
    {
        //delete m_dayTime;
    }
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
    pruh(semafor *s, laneDir dirOfLane, dayTimer* d, const std::string nameOfArm);
    double seconds() const;
    void setSeconds(double seconds);

    semafor *pSemafor() const;
    int counter() const;
    void setCounter(int counter);
    Facility& getF();
    dayTimer *getDayTimer() const;
    double currentSpawnTime();
    Histogram& getTabulka();
   /* ~pruh()
    {
        delete m_dayTimer;
        delete m_semafor;
    }*/
};

#endif // PRUH_H

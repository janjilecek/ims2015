#ifndef PRUH_H
#define PRUH_H
#include <simlib.h>
#include "semafor.h"
#include "generator.h"
#include <cmath>
#include <string>
#include "outputgnuplot.h"

#define HOURLENGTH 3600

class Generator;
enum armName
{
    HORNI,
    PRAVE,
    DOLNI,
    LEVE
};

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

class DayTimer : public Event
{
private:
    //dayTime* m_dayTime;
    dayTime m_dayTime;
    int m_currentTime;
    int m_currentHour;

    float m_loadNormalTime;
    int m_simulateHours;
    Semafor m_sem;

    float m_loadCurrent;
    float m_timePortion;
    float m_passIntersectionMin;
    float m_passIntersectionMax;
    float calculateLoad(float former, float latter);

public:
    static int simHours;
    static float multiplier;
    //dayTimer(dayTime* d, int seconds);
    DayTimer(float loadNormalTime, int simulateHours = 24, int startHour=0);
    void Behavior();
    int getCurrentTime() const;
    ~DayTimer()
    {
        //delete m_dayTime;
    }
    Semafor &getSem();
    dayTime &getDayTime();
    int &getCurrentHour();
    void setLoadCurrent(float loadCurrent);
};


enum laneDir
{
    ROVNE,
    DOPRAVA,
    DOLEVA
};

class Pruh
{
private:
    int m_counter;
    laneDir m_dirOfLane;
    DayTimer* m_dayTimer;
    const std::string m_nameOfArm;
    double m_seconds;
    Generator* m_generator;
    Facility f;
    Histogram tabulka;
    OutputGnuplot plt;
public:
    float multiplier;
    Pruh(armName namearm, DayTimer* d, const std::string nameOfArm);
    Pruh* setTiming(float s0e4, float s8e12, float s16e20);
    double seconds() const;
    void setSeconds(double seconds);
    int counter() const;
    void setCounter(int counter);
    Facility& getF();
    DayTimer *getDayTimer() const;
    Histogram& getTabulka();
   /* ~pruh()
    {
        delete m_dayTimer;
        delete m_semafor;
    }*/
    OutputGnuplot &getPlt();
};

#endif // PRUH_H

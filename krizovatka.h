#ifndef KRIZOVATKA_H
#define KRIZOVATKA_H
#include "rameno.h"
#include <simlib.h>
#include <iostream>
#include <vector>

#define HOURS6 21600

enum dayTime
{
    RANO,
    DOPOLEDNE,
    ODPOLEDNE,
    NOC
};

class dayTimer : public Event
{
private:
    dayTime timeOfDay;
public:
    dayTimer();
    void Behavior();
    dayTime getTimeOfDay() const;
};

class krizovatka
{
private:
    std::vector<rameno> ramena;
public:
    krizovatka();
};



#endif // KRIZOVATKA_H

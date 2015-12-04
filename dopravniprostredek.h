#ifndef DOPRAVNIPROSTREDEK_H
#define DOPRAVNIPROSTREDEK_H
#include <simlib.h>
#include "pruh.h"

//Facility silnice("Rameno0");

class pruh;
class dopravniProstredek : public Process
{
private:
    double prijezd;
    pruh* m_lane;
public:
    dopravniProstredek(pruh* lane) : m_lane(lane)
    {
        Activate(Time);
    }
    void Behavior();
};

#endif // DOPRAVNIPROSTREDEK_H

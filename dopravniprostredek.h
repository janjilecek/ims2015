#ifndef DOPRAVNIPROSTREDEK_H
#define DOPRAVNIPROSTREDEK_H
#include <simlib.h>
#include "pruh.h"

class Pruh;
class DopravniProstredek : public Process
{
private:
    double prijezd;
    Pruh* m_lane;
public:
    DopravniProstredek(Pruh* lane) : m_lane(lane)
    {
        Activate(Time);
    }
    void Behavior();
};

#endif // DOPRAVNIPROSTREDEK_H

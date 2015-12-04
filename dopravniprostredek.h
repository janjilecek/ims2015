#ifndef DOPRAVNIPROSTREDEK_H
#define DOPRAVNIPROSTREDEK_H
#include <simlib.h>
//#include "pruh.h"

//Facility silnice("Rameno0");

class dopravniProstredek : public Process
{
private:
    double prijezd;
    //pruh& m_lane;
public:
    //dopravniProstredek(pruh& lane) : m_lane(lane) {}
    dopravniProstredek();
    void Behavior();
};

#endif // DOPRAVNIPROSTREDEK_H

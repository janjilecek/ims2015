#include "dopravniprostredek.h"


void dopravniProstredek::Behavior()
{
    prijezd = Time;
    Seize(m_lane->getF());
    WaitUntil(m_lane->getDayTimer()->getSem().getPassable());
    Wait(Uniform(2.0,4.0));
    Release(m_lane->getF());
    m_lane->getTabulka()(Time);
}


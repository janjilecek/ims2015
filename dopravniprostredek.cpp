#include "dopravniprostredek.h"


void DopravniProstredek::Behavior()
{
    prijezd = Time;
    Seize(m_lane->getF());
    WaitUntil(m_lane->getDayTimer()->getSem().getPassable());
    Wait(Uniform(1.0,3.0));
    Release(m_lane->getF());
    m_lane->getTabulka()(Time);
    m_lane->getPlt()(Time);
}


#include "dopravniprostredek.h"


void dopravniProstredek::Behavior()
{
    prijezd = Time;
    Seize(m_lane->getF());
    WaitUntil(m_lane->pSemafor()->getPassable());
    Wait(Uniform(2.0,4.0)); // upravit podle denni doby
    Release(m_lane->getF());
    m_lane->getTabulka()(Time);
}


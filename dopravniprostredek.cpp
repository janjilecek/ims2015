#include "dopravniprostredek.h"


void dopravniProstredek::Behavior()
{
    prijezd = Time;
    Seize(m_lane->getF());
    WaitUntil(m_lane->pSemafor()->getPassable());
    Release(m_lane->getF());
    m_lane->getTabulka()(Time);
    Cancel();
}


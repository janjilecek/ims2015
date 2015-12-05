#include "dopravniprostredek.h"


void dopravniProstredek::Behavior()
{
    prijezd = Time;
    Print(prijezd);
    if (!m_lane->pSemafor()->getPassable())
    {
        Print("Stojim na cervene.");
    }
    else
    {
        Print("Projizdim");
    }

    Seize(*(m_lane->getF()));
    WaitUntil(m_lane->pSemafor()->getPassable());
    Release(*(m_lane->getF()));
    m_lane->setCounter(m_lane->counter() + 1);
    Print(Time-prijezd);
    Print("\n");
}


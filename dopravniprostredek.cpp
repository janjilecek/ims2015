#include "dopravniprostredek.h"


void dopravniProstredek::Behavior()
{
    prijezd = Time;
    if (m_lane->pSemafor()->getIsRed())
    {
        Print(Time);
        Print("Stojim na cervene.");
        Seize(*(m_lane->getF()));
        WaitUntil(m_lane->pSemafor()->getIsGreen());
        Release(*(m_lane->getF()));
        Print(Time-prijezd);
        m_lane->setCounter(m_lane->counter() + 1);
    }
    else
    {
        Print(Time-prijezd);
        Print("Projizdim");
        m_lane->setCounter(m_lane->counter() + 1);
    }
}


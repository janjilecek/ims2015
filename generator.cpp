#include "generator.h"

void generator::Behavior()
{
    auto* a = new dopravniProstredek(m_lane);
    a->Output();
    Activate(Time + Exponential(m_lane->seconds()));
}

#include "generator.h"

void generator::Behavior()
{
    auto* a = new dopravniProstredek();
    a->Activate();
    m_lane->Insert(a);
    a->Output();
    Activate(Time + Exponential(m_lane->seconds()));
}

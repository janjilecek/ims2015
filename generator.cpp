#include "generator.h"

void generator::Behavior()
{
    auto* a = new dopravniProstredek(m_lane);
    a->Activate();
    // spravit
    a->Output();
    Activate(Time + Exponential(m_lane->seconds()));
}

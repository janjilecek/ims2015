#include "generator.h"

void Generator::Behavior()
{
    new DopravniProstredek(m_lane);
    Activate(Time + Exponential(m_lane->getDayTimer()->getCurrentTime()));
}

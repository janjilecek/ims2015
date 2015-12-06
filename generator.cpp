#include "generator.h"

void generator::Behavior()
{
    new dopravniProstredek(m_lane);
    Activate(Time + Exponential(m_lane->getDayTimer()->getCurrentTime()));
}

#include "generator.h"

void generator::Behavior()
{
    new dopravniProstredek(m_lane);
    //a->Output();
    //m_lane->currentSpawnTime();
    Activate(Time + Exponential(m_lane->getDayTimer()->getCurrentTime()));
}

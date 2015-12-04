#include "semafor.h"

void semafor::Behavior()
{
    m_passable = !m_passable;
    Activate(Time + m_seconds);
}

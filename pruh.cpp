#include "pruh.h"

double pruh::seconds() const
{
    return m_seconds;
}

void pruh::setSeconds(double seconds)
{
    m_seconds = seconds;
}

pruh::pruh(semafor *s, double seconds, laneDir dirOfLane): m_dirOfLane(dirOfLane),
    m_semafor(s), m_seconds(seconds), m_generator(new generator(this))
{
    Print(m_dirOfLane);
}

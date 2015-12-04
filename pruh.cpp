#include "pruh.h"

double pruh::seconds() const
{
    return m_seconds;
}

void pruh::setSeconds(double seconds)
{
    m_seconds = seconds;
}

semafor *pruh::pSemafor() const
{
    return m_semafor;
}

int pruh::counter() const
{
    return m_counter;
}

void pruh::setCounter(int counter)
{
    m_counter = counter;
}

Facility* pruh::getF()
{
    return &f;
}

pruh::pruh(semafor *s, double seconds, laneDir dirOfLane): m_counter(0), m_dirOfLane(dirOfLane),
    m_semafor(s), m_seconds(seconds), m_generator(new generator(this)), f(this)
{
    Print(m_dirOfLane);
    m_generator->Activate();
}

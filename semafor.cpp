#include "semafor.h"


bool Semafor::getPassable() const
{
    return m_passable;
}

void Semafor::setSecondsRed(int secondsRed)
{
    m_secondsRed = secondsRed;
}

void Semafor::setSecondsGreen(int secondsGreen)
{
    m_secondsGreen = secondsGreen;
}

void Semafor::setPassable(bool passable)
{
    m_passable = passable;
}

void Semafor::Behavior()
{
    m_passable = !m_passable;
    if (m_passable)
    {
        //Print("Semafor ma zelenou %d s.\n", m_secondsGreen);
        Activate(Time + m_secondsGreen); // TODO upravit podle denni doby
    }
    else
    {
        //Print("Semafor ma cervenou %d s.\n", m_secondsRed);
        Activate(Time + m_secondsRed);
    }
}

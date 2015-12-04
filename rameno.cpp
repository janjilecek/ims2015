#include "rameno.h"

void rameno::setSeconds(int seconds)
{
    m_seconds = seconds;
}

rameno::rameno(armName name) : m_name(name)
{
    switch (m_name)
    {
    case HORNI:
        m_lanes.push_back(new pruh(new semafor(25), 164, ROVNE));
        m_lanes.push_back(new pruh(new semafor(25), 69, DOLEVA));
        break;
    case PRAVE:
        m_lanes.push_back(new pruh(new semafor(25), 23, DOPRAVA));
        m_lanes.push_back(new pruh(new semafor(25), 28, DOLEVA));
        break;
    case DOLNI:
        m_lanes.push_back(new pruh(new semafor(25), 31, DOPRAVA));
        m_lanes.push_back(new pruh(new semafor(25), 56, ROVNE));
        break;
    case LEVE:
        m_lanes.push_back(new pruh(new semafor(25), 129, DOLEVA));
        m_lanes.push_back(new pruh(new semafor(25), 17, ROVNE));
        m_lanes.push_back(new pruh(new semafor(25), 90, DOPRAVA));
        break;
    default:
        throw std::runtime_error("Error - Invalid semafor class initialization.");
    }
}

int rameno::seconds() const
{
    return m_seconds;
}

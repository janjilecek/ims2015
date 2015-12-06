#include "rameno.h"

std::vector<pruh *> rameno::lanes()
{
    return m_lanes;
}

rameno::rameno(armName name) : m_name(name)
{
    switch (m_name)
    {
    case HORNI:
        m_lanes.push_back(new pruh(new semafor, ROVNE, new dayTimer(164), "Horni rovne"));
        m_lanes.push_back(new pruh(new semafor, DOPRAVA, new dayTimer(69), "Horni doleva"));
        break;
    case PRAVE:
        m_lanes.push_back(new pruh(new semafor, DOPRAVA, new dayTimer(23), "Prave doprava"));
        m_lanes.push_back(new pruh(new semafor, DOLEVA, new dayTimer(28), "Prave doleva"));
        break;
    case DOLNI:
        m_lanes.push_back(new pruh(new semafor, DOPRAVA, new dayTimer(31), "Dolni doprava"));
        m_lanes.push_back(new pruh(new semafor, ROVNE, new dayTimer(56), "Dolni rovne"));
        break;
    case LEVE:
        m_lanes.push_back(new pruh(new semafor, DOLEVA, new dayTimer(129), "Leve doleva"));
        m_lanes.push_back(new pruh(new semafor, ROVNE, new dayTimer(17), "Leve rovne"));
        m_lanes.push_back(new pruh(new semafor, DOPRAVA, new dayTimer(90), "Leve doprava"));
        break;
    default:
        throw std::runtime_error("Error - Invalid semafor class initialization.");
    }
}

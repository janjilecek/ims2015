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
        m_lanes.push_back((new pruh(m_name, new dayTimer(164, 1, 8), "Horni rovne"))->setTiming(0.09,1.81,1.81));
    /*    m_lanes.push_back((new pruh(m_name, new dayTimer(69), "Horni doleva"))->setTiming(0.12,1.23,1.23));
        break;
    case PRAVE:
        m_lanes.push_back((new pruh(m_name, new dayTimer(23), "Prave doprava"))->setTiming(0.13,2.70,1.81));
        m_lanes.push_back((new pruh(m_name, new dayTimer(28), "Prave doleva"))->setTiming(0.25,2.23,1.81));
        break;
    case DOLNI:
        m_lanes.push_back((new pruh(m_name, new dayTimer(31), "Dolni doprava"))->setTiming(0.07,1.69,1.81));
        m_lanes.push_back((new pruh(m_name, new dayTimer(56), "Dolni rovne"))->setTiming(0.09,0.88,1.81));
        break;
    case LEVE:
        m_lanes.push_back((new pruh(m_name, new dayTimer(129), "Leve doleva"))->setTiming(0.21,2.57,1.81));
        m_lanes.push_back((new pruh(m_name, new dayTimer(17), "Leve rovne"))->setTiming(0.20,2.11,1.81));
        m_lanes.push_back((new pruh(m_name, new dayTimer(90), "Leve doprava"))->setTiming(0.2,1.4,1.81));
        break;
    default:
        throw std::runtime_error("Error - Invalid semafor class initialization.");*/
    }
}

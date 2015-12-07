#include "rameno.h"

#define DAYTESTING
#define TESTHOUR 8

std::vector<pruh *> rameno::lanes()
{
    return m_lanes;
}

rameno::rameno(armName name) : m_name(name)
{
    #ifdef DAYTESTING
    switch (m_name)
    {

    case HORNI:
        m_lanes.push_back((new pruh(m_name, new dayTimer(164), "Horni rovne"))->setTiming(0.09,0.90,0.90));
        m_lanes.push_back((new pruh(m_name, new dayTimer(69), "Horni doleva"))->setTiming(0.12,0.62,1.38));
        break;
    case PRAVE:
        m_lanes.push_back((new pruh(m_name, new dayTimer(23), "Prave doprava"))->setTiming(0.25,1.12,0.70));
        m_lanes.push_back((new pruh(m_name, new dayTimer(28), "Prave doleva"))->setTiming(0.14,1.35,1.17));
        break;
    case DOLNI:
        m_lanes.push_back((new pruh(m_name, new dayTimer(31), "Dolni doprava"))->setTiming(0.07,0.85,1.02));
        m_lanes.push_back((new pruh(m_name, new dayTimer(56), "Dolni rovne"))->setTiming(0.09,0.44,0.81));
        break;
    case LEVE:
        m_lanes.push_back((new pruh(m_name, new dayTimer(129), "Leve doleva"))->setTiming(0.21,1.29,1.43));
        m_lanes.push_back((new pruh(m_name, new dayTimer(17), "Leve rovne"))->setTiming(0.20,1.06,1.57));
        m_lanes.push_back((new pruh(m_name, new dayTimer(90), "Leve doprava"))->setTiming(0.2,0.7,1.2));
        break;
    default:
        throw std::runtime_error("Error - Invalid semafor class initialization.");
    }
    #endif
    #ifndef DAYTESTING
    switch (m_name)
    {

    case HORNI:
        m_lanes.push_back((new pruh(m_name, new dayTimer(164, 1, TESTHOUR), "Horni rovne"))->setTiming(0.09,0.90,0.90));
        m_lanes.push_back((new pruh(m_name, new dayTimer(69, 1, TESTHOUR), "Horni doleva"))->setTiming(0.12,0.62,1.38));
        break;
    case PRAVE:
        m_lanes.push_back((new pruh(m_name, new dayTimer(23, 1, TESTHOUR), "Prave doprava"))->setTiming(0.25,1.12,0.70));
        m_lanes.push_back((new pruh(m_name, new dayTimer(28, 1, TESTHOUR), "Prave doleva"))->setTiming(0.14,1.35,1.17));
        break;
    case DOLNI:
        m_lanes.push_back((new pruh(m_name, new dayTimer(31, 1, TESTHOUR), "Dolni doprava"))->setTiming(0.07,0.85,1.02));
        m_lanes.push_back((new pruh(m_name, new dayTimer(56, 1, TESTHOUR), "Dolni rovne"))->setTiming(0.09,0.44,0.81));
        break;
    case LEVE:
        m_lanes.push_back((new pruh(m_name, new dayTimer(129, 1, TESTHOUR), "Leve doleva"))->setTiming(0.21,1.29,1.43));
        m_lanes.push_back((new pruh(m_name, new dayTimer(17, 1, TESTHOUR), "Leve rovne"))->setTiming(0.20,1.06,1.57));
        m_lanes.push_back((new pruh(m_name, new dayTimer(90, 1, TESTHOUR), "Leve doprava"))->setTiming(0.2,0.7,1.2));
        break;
    default:
        throw std::runtime_error("Error - Invalid semafor class initialization.");
    }
    #endif
}

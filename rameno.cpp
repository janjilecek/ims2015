#include "rameno.h"

std::vector<pruh *> rameno::lanes()
{
    return m_lanes;
}

rameno::rameno(armName name) : m_name(name)
{
    //m_dayTime = new dayTime(0.1,0.2,1.5,1,1.6,0.4,0.1,2);
    switch (m_name)
    {
    case HORNI:
        //m_lanes.push_back(new pruh(ROVNE, (new dayTimer(m_dayTime, 164)), "Horni rovne", new semafor(20, 25)));
        //m_lanes.push_back(new pruh(new semafor(20, 25),  DOPRAVA, new dayTimer(0,1,2.5,0.2,23,0.1,4), "Prave doprava"));
        m_lanes.push_back(new pruh(new semafor(20,25), DOPRAVA, new dayTimer(0,1,1,1,169,0.1,0.2), "Horni doprava"));
      // m_lanes.push_back(new pruh(new semafor(20, 25), DOLEVA, (new dayTimer(m_dayTime, 69)), "Horni doleva"));
        //m_lanes.push_back(new pruh(new semafor(20, 25), 23, DOPRAVA, (new dayTimer(0,1,2.5,0.2,23,0.1,4)), "Prave doprava"));
        break;
    case PRAVE:
       // m_lanes.push_back(new pruh(new semafor(20, 25), 23, DOPRAVA, (new dayTimer(0,1,2.5,0.2,23,0.1,4)), "Prave doprava"));
       // m_lanes.push_back(new pruh(new semafor(20, 25), 28, DOLEVA, (new dayTimer(0,1,2.5,0.2,28,0.1,4)), "Prave doleva"));
        break;
    case DOLNI:
      //  m_lanes.push_back(new pruh(new semafor(20, 25), 31, DOPRAVA, (new dayTimer(0,1,2.5,0.2,31,0.1,4)), "Dolni doprava"));
      //  m_lanes.push_back(new pruh(new semafor(20, 25), 56, ROVNE, (new dayTimer(0,1,2.5,0.2,56,0.1,4)), "Dolni rovne"));
        break;
    case LEVE:
      //  m_lanes.push_back(new pruh(new semafor(20, 25), 129, DOLEVA, (new dayTimer(0,1,2.5,0.2,129,0.1,4)), "Leve doleva"));
     //   m_lanes.push_back(new pruh(new semafor(20, 25), 17, ROVNE, (new dayTimer(0,1,2.5,0.2,17,0.1,4)), "Leve rovne"));
      //  m_lanes.push_back(new pruh(new semafor(20, 25), 90, DOPRAVA, (new dayTimer(0,1,1,1,90,0.1,4)), "Leve doprava"));
        break;
    default:
        throw std::runtime_error("Error - Invalid semafor class initialization.");
    }
}

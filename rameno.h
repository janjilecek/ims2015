#ifndef RAMENO_H
#define RAMENO_H
#include <vector>
#include <simlib.h>
#include "semafor.h"
#include "pruh.h"
#include <stdexcept>




class Rameno
{
private:
    dayTime *m_dayTime;
    armName m_name;
    std::vector<Pruh*> m_lanes;
    DayTimer* m_dayTimer;
public:
    Rameno(armName name);
    std::vector<Pruh *> lanes();

};

#endif // RAMENO_H

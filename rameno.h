#ifndef RAMENO_H
#define RAMENO_H
#include <vector>
#include <simlib.h>
#include "semafor.h"
#include "pruh.h"
#include <stdexcept>




class rameno
{
private:
    dayTime *m_dayTime;
    armName m_name;
    std::vector<pruh*> m_lanes;
    dayTimer* m_dayTimer;
public:
    rameno(armName name);
    std::vector<pruh *> lanes();

};

#endif // RAMENO_H

#ifndef RAMENO_H
#define RAMENO_H
#include <vector>
#include <simlib.h>
#include "semafor.h"
#include "pruh.h"
#include <stdexcept>

enum armName
{
    HORNI,
    PRAVE,
    DOLNI,
    LEVE
};


class rameno
{
private:
    armName m_name;
    int m_seconds;
    std::vector<pruh*> m_lanes;
    dayTimer* m_dayTimer;
public:
    rameno(armName name);
    int seconds() const;
    void setSeconds(int seconds);
    std::vector<pruh *> lanes();
};

#endif // RAMENO_H

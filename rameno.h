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
public:
    rameno(armName name);
    int seconds() const;
    void setSeconds(int seconds);
};

#endif // RAMENO_H

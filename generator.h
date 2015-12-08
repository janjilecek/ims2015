#ifndef GENERATOR_H
#define GENERATOR_H
#include <simlib.h>
#include "pruh.h"
#include "dopravniprostredek.h"


class Pruh;
class Generator : public Event
{
private:
    Pruh* m_lane;
public:
    Generator(Pruh* lane) : m_lane(lane)
    {

        Activate(Time);
    }
    void Behavior();
};

#endif // GENERATOR_H

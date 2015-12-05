#ifndef GENERATOR_H
#define GENERATOR_H
#include <simlib.h>
#include "pruh.h"
#include "dopravniprostredek.h"


class pruh;
class generator : public Event
{
private:
    pruh* m_lane;
public:
    generator(pruh* lane) : m_lane(lane)
    {

        Activate(Time);
    }
    void Behavior();
};

#endif // GENERATOR_H

#ifndef PRUH_H
#define PRUH_H
#include <simlib.h>
#include "semafor.h"
#include "generator.h"

class generator;
enum laneDir
{
    ROVNE,
    DOPRAVA,
    DOLEVA
};

class pruh : public Queue
{
private:
    laneDir m_dirOfLane;
    semafor *m_semafor;
    double m_seconds;
    generator* m_generator;
public:
    pruh(semafor *s, double seconds, laneDir dirOfLane);
    double seconds() const;
    void setSeconds(double seconds);

};

#endif // PRUH_H

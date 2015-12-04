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
    int m_counter;
    laneDir m_dirOfLane;
    semafor *m_semafor;
    double m_seconds;
    generator* m_generator;
    Facility f;
public:
    pruh(semafor *s, double seconds, laneDir dirOfLane);
    double seconds() const;
    void setSeconds(double seconds);

    semafor *pSemafor() const;
    int counter() const;
    void setCounter(int counter);
    Facility* getF();
};

#endif // PRUH_H

#ifndef SEMAFOR_H
#define SEMAFOR_H
#include <simlib.h>


class semafor : public Event
{
private:
    int m_seconds;
    bool m_passable;
public:
    semafor(int seconds) : m_seconds(seconds), m_passable(false) {}
    void Behavior();
};

#endif // SEMAFOR_H

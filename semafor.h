#ifndef SEMAFOR_H
#define SEMAFOR_H
#include <simlib.h>


class semafor : public Event
{
private:
    int m_secondsGreen;
    int m_secondsRed;
    bool m_passable;

public:
    semafor(int secondsGreen, int secondsRed) : m_secondsGreen(secondsGreen), m_secondsRed(secondsRed),
        m_passable(false)
    {
        Activate(Time);
    }
    void Behavior();

    bool getPassable() const;
};

#endif // SEMAFOR_H

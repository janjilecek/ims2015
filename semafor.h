#ifndef SEMAFOR_H
#define SEMAFOR_H
#include <simlib.h>


class Semafor : public Event
{
private:
    int m_secondsGreen;
    int m_secondsRed;
    bool m_passable;

public:
    Semafor(int secondsGreen, int secondsRed) : m_secondsGreen(secondsGreen), m_secondsRed(secondsRed),
        m_passable(false)
    {
        Activate(Time);
    }
    Semafor() : m_secondsGreen(20), m_secondsRed(25), m_passable(false)
    {
        Activate(Time);
    }

    void Behavior();

    bool getPassable() const;
    void setSecondsRed(int secondsRed);
    void setSecondsGreen(int secondsGreen);
    void setPassable(bool passable);
};

#endif // SEMAFOR_H

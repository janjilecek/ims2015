#ifndef SEMAFOR_H
#define SEMAFOR_H
#include <simlib.h>


class semafor : public Event
{
private:
    int m_secondsGreen;
    int m_secondsRed;
    bool isRed;
    bool isGreen;
    //bool m_passable;

public:
    semafor(int secondsGreen, int secondsRed) : m_secondsGreen(secondsGreen), m_secondsRed(secondsRed),
        isRed(true), isGreen(false)
    {
        Activate();
    }
    void Behavior();
    bool getIsRed() const;
    bool getIsGreen() const;
};

#endif // SEMAFOR_H

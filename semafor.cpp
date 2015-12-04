#include "semafor.h"



bool semafor::getIsRed() const
{
    return isRed;
}

bool semafor::getIsGreen() const
{
    return isGreen;
}

void semafor::Behavior()
{
    isRed = !isRed;
    isGreen = !isGreen;
    Activate(Time + m_secondsRed);
    //Activate(Time + m_secondsGreen);
    //isGreen = false;
    //isRed = true;
}

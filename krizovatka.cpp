#include "krizovatka.h"

krizovatka::krizovatka()
{
    for (int i = 0; i < 4; ++i)
    {
        rameno r((armName)i);
        ramena.push_back(r);
    }
}


dayTime dayTimer::getTimeOfDay() const
{
    return timeOfDay;
}

dayTimer::dayTimer()
{
    timeOfDay = NOC; // prvni inkrementace v timeru bude rano
}

void dayTimer::Behavior()
{
    timeOfDay = (dayTime) ((timeOfDay+1)%4); // zmena denni doby na dalsi v cyklu
    Activate(Time + HOURS6);
}

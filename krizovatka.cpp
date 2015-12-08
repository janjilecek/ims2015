#include "krizovatka.h"

std::vector<Rameno> Krizovatka::getRamena() const
{
    return ramena;
}

Krizovatka::Krizovatka()
{
    for (int i = 0; i < 4; ++i)
    {
        Rameno r((armName)i);
        ramena.push_back(r);
    }
}



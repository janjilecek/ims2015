#include "krizovatka.h"

std::vector<rameno> krizovatka::getRamena() const
{
    return ramena;
}

krizovatka::krizovatka()
{
    for (int i = 0; i < 1; ++i) // zmen zpet na 4
    {
        rameno r((armName)i);
        ramena.push_back(r);
    }
}



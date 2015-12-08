#ifndef KRIZOVATKA_H
#define KRIZOVATKA_H
#include "rameno.h"
#include <simlib.h>
#include <iostream>
#include <vector>
#include <cmath>


class Krizovatka
{
private:
    std::vector<Rameno> ramena;
public:
    Krizovatka();
    std::vector<Rameno> getRamena() const;
};



#endif // KRIZOVATKA_H

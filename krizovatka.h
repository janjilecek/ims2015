#ifndef KRIZOVATKA_H
#define KRIZOVATKA_H
#include "rameno.h"
#include <simlib.h>
#include <iostream>
#include <vector>
#include <cmath>


class krizovatka
{
private:
    std::vector<rameno> ramena;
public:
    krizovatka();
    std::vector<rameno> getRamena() const;
};



#endif // KRIZOVATKA_H

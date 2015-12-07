#include <iostream>
#include <simlib.h>
#include "krizovatka.h"
#include <ctime>
using namespace std;

int main()
{
   // SetOutput("krizovatka.dat");
    RandomSeed(time(NULL)); // pridat time random
    Init(0,dayTimer::simHours*HOURLENGTH);
    krizovatka k;

    Run();
    for (auto &arm : k.getRamena())
    {
        for (auto &lane : arm.lanes())
        {
            lane->getF().Output();
            lane->getTabulka().Output();
            //lane->getPlt().Output();
        }
    }

}

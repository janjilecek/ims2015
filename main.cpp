#include <iostream>
#include <simlib.h>
#include "krizovatka.h"

using namespace std;

int main()
{
   // SetOutput("krizovatka.dat");
    RandomSeed(125464); // pridat time random
    Init(0,dayTimer::simHours*HOURLENGTH);
    krizovatka k;

    Run();
    for (auto &arm : k.getRamena())
    {
        for (auto &lane : arm.lanes())
        {
            //lane->getF().Output();
            //lane->getTabulka().Output();
            lane->getPlt().Output();
        }
    }

}

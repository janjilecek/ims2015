#include <iostream>
#include <simlib.h>
#include "krizovatka.h"

using namespace std;

int main()
{
   // SetOutput("krizovatka.dat");
    //RandomSeed(125464);
    Init(0,HOURS*HOURLENGTH);
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

    /*RandomSeed(5646578);
    Init(0,HOURS*HOURLENGTH);
    krizovatka kk;

    Run();
    for (auto &arm : kk.getRamena())
    {
        for (auto &lane : arm.lanes())
        {
            lane->getF().Output();
            lane->getTabulka().Output();
        }
    }*/
}

#include <iostream>
#include <simlib.h>
#include "krizovatka.h"

using namespace std;

int main()
{
    Init(0,HOURS*HOURLENGTH);
    krizovatka k;

    Run();
    for (auto &a : k.getRamena())
    {
        for (pruh* b : a.lanes())
        {
            b->getF().Output();
            b->getTabulka().Output();
        }
    }
}

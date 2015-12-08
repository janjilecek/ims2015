#include <iostream>
#include <simlib.h>
#include "krizovatka.h"
#include <ctime>
#include <random>
#include "dataformatter.h"

#define DAYTESTING


int main(int argc, char** argv)
{
    //SetOutput("krizovatka.dat");
    if (argc == 2)
    {
        std::istringstream ss(argv[1]);
        float x;
        if (!(ss >> x))
            std::cerr << "Invalid number " << argv[1] << '\n';
        DayTimer::multiplier = x;
    }
    #ifdef DAYTESTING
    int pokusy = 1;
    #endif
    #ifndef DAYTESTING
    int pokusy = 200;
    #endif
    for (int i = 0; i < pokusy; ++i)
    {
        srand(i);
        RandomSeed(time(NULL)*rand());
        Init(0,DayTimer::simHours*HOURLENGTH);

        Krizovatka k;


        Run();
        for (auto &arm : k.getRamena())
        {
            for (Pruh *lane : arm.lanes())
            {

                lane->getF().Output();
                lane->getTabulka().Output();
                //lane->getPlt().Output();

                #ifndef DAYTESTING
                CustomOutput::queueOut(lane->getF().Name(), lane->getF().Q1->StatN.Max(), true);
                CustomOutput::queueOut(lane->getF().Name(), lane->getF().Q1->StatDT.Max(), false
                #endif
            }
        }
    }
    #ifndef DAYTESTING
    DataFormatter::countAverageToFile();
    #endif
}

#include <iostream>
#include <simlib.h>
#include "krizovatka.h"
#include <ctime>
#include <random>
#include "dataformatter.h"

using namespace std;

int main(int argc, char** argv)
{
   // SetOutput("krizovatka.dat");
    if (argc == 2)
    {
        std::istringstream ss(argv[1]);
        int x;
        if (!(ss >> x))
            cerr << "Invalid number " << argv[1] << '\n';
        dayTimer::multiplier = x;
    }
    int pokusy = 200;
    for (int i = 0; i < pokusy; ++i)
    {
        srand(i);
        RandomSeed(time(NULL)*rand());
        Init(0,dayTimer::simHours*HOURLENGTH);

        krizovatka k;


        Run();
        for (auto &arm : k.getRamena())
        {
            for (pruh *lane : arm.lanes())
            {
                //lane->getF().Output();
                CustomOutput::queueOut(lane->getF().Name(), lane->getF().Q1->StatN.Max(), true);
                CustomOutput::queueOut(lane->getF().Name(), lane->getF().Q1->StatDT.Max(), false);
               // lane->getTabulka().Output();
                lane->getPlt().Output();
            }
        }
    }
    DataFormatter::countAverageToFile();


}

#include <iostream>
#include <simlib.h>
#include "krizovatka.h"

using namespace std;



int main()
{
    Init(0,3600*48);
    dayTimer d(0,0.5,1.3,0.1,48,0.01,5.0);
    Run();
}

#include <iostream>
#include <simlib.h>
#include "krizovatka.h"

using namespace std;

int main()
{
    Print("IMS projekt krizovatka\n");
    SetOutput("model.out");
    Init(0,3000);
    /*semafor *s = new semafor(25);
    pruh *p = new pruh(s, 48, ROVNE);
    (new generator(p))->Activate();*/
    krizovatka k;


}


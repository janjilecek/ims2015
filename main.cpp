#include <iostream>
#include <simlib.h>
#include "krizovatka.h"

using namespace std;

const int semaforGreen = 20;
const int semaforRed = 25;
const int laneStraight = 164;
const int laneLeft = 69;

/*
Facility lane("Horni");

long ncount = 0;

class Timeout : public Event
{
    Process *ptr;
public:
    Timeout(double t, Process *p) : ptr(p)
    {
        Activate(Time+t);
    }
    void Behavior()
    {
        ptr->Out();
    }
};*/




int main()
{
    Print("IMS projekt krizovatka\n");
    Init(0,3000);
    krizovatka k;
    Run();


}


#include <iostream>
#include <simlib.h>
//#include "krizovatka.h"

using namespace std;

const int semaforGreen = 20;
const int semaforRed = 25;
const int laneStraight = 164;
const int laneLeft = 69;

Queue q;
Facility lane("Horni", q);
Histogram Tabulka("Tabulka", 0, 60, 30);
long ncount = 0;

class Semafor : public Event
{
    int seconds;
    int red;
public:
    bool passable;
    Semafor(int sec) : seconds(sec), passable(false)
    {
        Activate(Time);
    }
    Semafor()
    {
        red = 1;
        seconds = 1;
        passable = false;
        Activate(Time);
    }

    void Behavior()
    {
        if (passable)
        {
            Activate(Time + seconds);
        }
        else
        {
            Activate(Time + red);
        }
        passable = !passable;

    }
};

class Auto : public Process
{
    double prichod;
    Semafor* s;

    void Behavior()
    {
        prichod = Time;
        if (s->passable) Print("Zelena");
        else Print("Cervena");
        Print(prichod);
        Seize(lane);
        if (!s->passable) WaitUntil(s->passable);
        Release(lane);
        if (s->passable) Print("Zelena");
        else Print("Cervena");
        Print(Time);
        ncount++;
        lane.Output();

    }
public:
    Auto(Semafor* ss) : s(ss) {}
};

class Generator : public Event
{
    Semafor* s;
public:
    Generator() : s(new Semafor()) {}
    void Behavior()
    {
        auto* a = new Auto(s);
        (a)->Activate();
        a->Output();
        Activate(Time+Exponential(17));
    }
};

int main()
{
    Print("Zacatek IMS simulace krizovatky\n");
    Init(0,1800);
    (new Generator)->Activate();
    Run();
    Print("Pocet aut: %d \n", ncount);
    lane.Output();
    Tabulka.Output();
}


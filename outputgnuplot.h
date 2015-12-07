#ifndef OUTPUTGNUPLOT_H
#define OUTPUTGNUPLOT_H
#include <simlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class OutputGnuplot : public Histogram
{
    int m_hours;
public:
    OutputGnuplot(const char *_name, double low, double step, unsigned count, int hours);
    virtual void Output() override;
};

class CustomOutput
{
public:
    static void queueOut(std::string name, int inp);
};

#endif // OUTPUTGNUPLOT_H

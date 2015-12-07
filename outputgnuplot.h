#ifndef OUTPUTGNUPLOT_H
#define OUTPUTGNUPLOT_H
#include <simlib.h>

class OutputGnuplot : public Histogram
{
public:
    OutputGnuplot(const char *_name, double low, double step, unsigned count=10) : Histogram(_name, low, step, count) {}
    virtual void Output() override;
};

#endif // OUTPUTGNUPLOT_H

#ifndef OUTPUTGNUPLOT_H
#define OUTPUTGNUPLOT_H
#include <simlib.h>

class OutputGnuplot : public Histogram
{
    int m_hours;
public:
    OutputGnuplot(const char *_name, double low, double step, unsigned count, int hours);
    virtual void Output() override;
};

#endif // OUTPUTGNUPLOT_H

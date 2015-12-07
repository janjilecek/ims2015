#include "outputgnuplot.h"

void OutputGnuplot::Output()
{
    long sum = 0;
    unsigned i;
    for (i=0; i<=count+1; i++)
      sum += dptr[i];
    if (sum==0) return;
    double from,to;
    long s;
    from = low;
    s = dptr[0];
    for (i=1; i<=count; i++)
    {
      unsigned x = dptr[i];
      s += x;
      to = from+step;
      int hour = from/3600;
      Print("%d %8u \n",hour, x);
      //Print(" %8u \n", x);
      from = to;
    }
    Print("\n");
}


#include "outputgnuplot.h"


OutputGnuplot::OutputGnuplot(const char *_name, double low, double step, unsigned count=10, int hours=24) :
    Histogram(_name, low, step, count),
    m_hours(hours) {}

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
      if (m_hours == 24)
      {
        Print("%d %u\n",hour, x);
      }
      else
      {
          std::ofstream myfile;
          myfile.open (Name(), std::ios::out | std::ios::app);
          myfile << x << std::endl;
          myfile.close();
      }
      from = to;
    }
    Print("\n");
}


void CustomOutput::queueOut(std::string name, int inp)
{
    std::ostringstream oss;
    oss << name << "_queue.imsdat";
    std::ofstream myfile;
    myfile.open (oss.str(), std::ios::out | std::ios::app);
    myfile << inp << std::endl;
    myfile.close();
}

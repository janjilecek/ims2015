#ifndef DATAFORMATTER_H
#define DATAFORMATTER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class DataFormatter
{
public:
    DataFormatter();
    static void countAverageToFile();
    static void packToOneFile();
};

#endif // DATAFORMATTER_H

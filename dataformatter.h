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
    static void countAverageToFile(std::string suffix=".avg");
};

#endif // DATAFORMATTER_H

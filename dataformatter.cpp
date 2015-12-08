#include "dataformatter.h"

DataFormatter::DataFormatter()
{

}

void DataFormatter::countAverageToFile()
{
    std::vector<std::string> names;
    names.push_back("Horni rovne");
    names.push_back("Horni doleva");
    names.push_back("Prave doprava");
    names.push_back("Prave doleva");
    names.push_back("Dolni doprava");
    names.push_back("Dolni rovne");
    names.push_back("Leve doleva");
    names.push_back("Leve rovne");
    names.push_back("Leve doprava");
    names.push_back("Horni rovne_queue.imsdat");
    names.push_back("Horni doleva_queue.imsdat");
    names.push_back("Prave doprava_queue.imsdat");
    names.push_back("Prave doleva_queue.imsdat");
    names.push_back("Dolni doprava_queue.imsdat");
    names.push_back("Dolni rovne_queue.imsdat");
    names.push_back("Leve doleva_queue.imsdat");
    names.push_back("Leve rovne_queue.imsdat");
    names.push_back("Leve doprava_queue.imsdat");

    std::ofstream myf;
    myf.open ("output.avg", std::ios::out | std::ios::app);
    for (auto &filename : names)
    {
        std::ifstream myfile(filename);
        std::string line;

        std::vector<int> v;
        while (std::getline(myfile, line))
        {
            std::istringstream iss(line);
            int n;
            while (iss >> n)
            {
                v.push_back(n);
            }
        }
        myfile.close();
        float res = 0;
        for (auto &num : v)
        {
            res += num;
        }
        res /= (float) v.size();

        std::ostringstream oss;
        oss << filename << "," << (int)res << std::endl;
        myf << oss.str();


    }
    myf.close();



}


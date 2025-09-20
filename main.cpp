#include <iostream>
#include <fstream>
#include "coordinateSystems.h"
#include "classes.hpp"

using namespace std;


int main(int argc, char *argv[])
{
    ifstream csvFile("iata-icao.csv");

    if (!csvFile.is_open()) {
        cerr << "Error opening file: " << "iata-icao.csv" << endl;
        return 1;
    }

    string line;
    streampos startPos = csvFile.tellg();

    if (getline(csvFile, line))
    {
        const string header = "country_code,region_name,iata,icao,airport,latitude,longitude";
        line = removequotes(line);
        if (!line.empty() && line.back() == '\r') line.pop_back();

        if (line == header);
        else
        {
            csvFile.clear();
            csvFile.seekg(startPos);
        }
    }

    while(getline(csvFile, line))
    {
        auto fields = parsecsv(line);

        Airports::listofairports.emplace_back(fields[0], fields[1], fields[2], fields[3], fields[4], stod(fields[5]), stod(fields[6]));
    }

    csvFile.close();



    return 0;
}

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
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

    

    while (1)
    {
        double latx=0, lony=0;
        char u_in[100];
        scanf("%99[^\n]", u_in);
        getchar();

        u_in[strcspn(u_in, "\n")] = '\0';

        if (strcmp(u_in, "stop") == 0)
            break;

        sscanf(u_in, "%lf %lf", &latx, &lony);

        //cout << latx << lony << endl;

        size_t index = 0;
        for (const auto& airport : Airports::listofairports)
        {
            auto d = distancecalc(latx, lony, 0.0, *(airport.latitude), *(airport.longitude), 0.0, 60);
            if (d.lessthanparam)
            {
                //cout << "matching index is " << index << endl;

                Airports::distances.push_back(new Airports::temp(index, d.distance));
            }
            ++index;
        }

        sort(Airports::distances.begin(), Airports::distances.end(), distcompare);

        int counter = 1;
        for (const auto& d : Airports::distances)
        {
            const auto& airport = Airports::listofairports[d->matchindex];

            printf("%d) %s %lf %lf distance (miles) %lf\n",
                counter,
                airport.airport->c_str(),
                *airport.latitude,
                *airport.longitude,
                d->distance);
            ++counter;
        }

        for (auto d : Airports::distances)
        {
            delete d;
        }
        Airports::distances.clear();
    };

    return 0;
}

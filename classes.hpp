#pragma once
#include <string>
#include <vector>

namespace Airports
{
    class Airport
    {
    public:
        std::string country_code;
        std::string region_name;
        std::string iata;
        std::string icao;
        std::string airport;
        double latitude;
        double longitude;

        Airport(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, double s6, double s7);
    };

    class temp
    {
    public:
        int matchindex;
        double distance;
        temp(int x, double y);
    };

    std::vector<Airport> listofairports;
    std::vector<temp> distances;
};

double distance(double lat, double lon, double searchRad);

std::string removequotes(const std::string& input);

std::vector<std::string> parsecsv(const std::string& line);
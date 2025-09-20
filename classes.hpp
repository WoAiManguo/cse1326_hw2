#pragma once
#include <string>
#include <vector>

namespace Airports
{
    class Airport
    {
    public:
        std::string* country_code;
        std::string* region_name;
        std::string* iata;
        std::string* icao;
        std::string* airport;
        double* latitude;
        double* longitude;


        Airport(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, double s6, double s7);
        ~Airport();
        Airport(const Airport& other);
        Airport& operator=(const Airport& other);
    };

    class temp
    {
    public:
        int matchindex;
        double distance;
        temp(int x, double y);
    };

    extern std::vector<Airport> listofairports;
    extern std::vector<temp*> distances;
};

bool distcompare(const Airports::temp* a, const Airports::temp* b);

struct distance
{
    bool lessthanparam;
    double distance;
};

struct distance distancecalc(double lat, double lon, double alt, double latOf,double lonOf, double altOf, double searchRad);

std::string removequotes(const std::string& input);

std::vector<std::string> parsecsv(const std::string& line);
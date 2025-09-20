#include "classes.hpp"
#include <string>
#include <algorithm>
#include <sstream>

namespace Airports
{
    temp::temp(int x, double y)
    {
        matchindex = x;
        distance = y;
    }

    Airport::Airport(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, double s6, double s7)
    {
        country_code = s1;
        region_name = s2;
        iata = s3;
        icao = s4;
        airport = s5;
        latitude = s6;
        longitude = s7;
    }
}

double distance(double lat, double lon, double searchRad)
{
    double dist = 0;



    return dist;
}

std::string removequotes(const std::string& input)
{
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), '"'), result.end());
    return result;
}

std::vector<std::string> parsecsv(const std::string& line)
{
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;
    while (std::getline(ss, field, ','))
    {
        fields.push_back(removequotes(field));
    }
    return fields;
}
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
        country_code = new std::string(s1);
        region_name = new std::string(s2);
        iata = new std::string(s3);
        icao = new std::string(s4);
        airport = new std::string(s5);
        latitude = new double(s6);
        longitude = new double(s7);
    }
    Airport::~Airport()
    {
        delete country_code;
        delete region_name;
        delete iata;
        delete icao;
        delete airport;
        delete latitude;
        delete longitude;
    }
    Airport::Airport(const Airport& other)
    {
        country_code = new std::string(*other.country_code);
        region_name = new std::string(*other.region_name);
        iata = new std::string(*other.iata);
        icao = new std::string(*other.icao);
        airport = new std::string(*other.airport);
        latitude = new double(*other.latitude);
        longitude = new double(*other.longitude);
    }
    Airport& Airport::operator=(const Airport& other)
    {
        if (this != &other) {
            *country_code = *other.country_code;
            *region_name = *other.region_name;
            *iata = *other.iata;
            *icao = *other.icao;
            *airport = *other.airport;
            *latitude = *other.latitude;
            *longitude = *other.longitude;
        }
        return *this;
    }

    std::vector<Airport> listofairports;
    std::vector<temp> distances;
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
    bool inQuotes = false;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];

        if (c == '"') {
            inQuotes = !inQuotes;
        }
        else if (c == ',' && !inQuotes) {
            fields.push_back(field);
            field.clear();
        }
        else {
            field.push_back(c);
        }
    }
    fields.push_back(removequotes(field));
    return fields;
}
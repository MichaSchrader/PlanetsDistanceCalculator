#ifndef DISTANCECALCULATOR_H
#define DISTANCECALCULATOR_H

#include <string>
class DistanceCalculator
{
public:
    DistanceCalculator();
    long long int calculateDistance(std::string, std::string, long long day);
private:
    std::tuple<double, double, double> positionOfPlanet(std::string planet, double time);
    std::tuple<double, double, double> positionOfSun(double time);
    std::tuple<double, double, double> positionOfMercury(double time);
    std::tuple<double, double, double> positionOfVenus(double time);
    std::tuple<double, double, double> positionOfEarth(double time);
    std::tuple<double, double, double> positionOfMars(double time);
    std::tuple<double, double, double> positionOfJupiter(double time);
    std::tuple<double, double, double> positionOfSaturn(double time);
    std::tuple<double, double, double> positionOfUranus(double time);
    std::tuple<double, double, double> positionOfNeptune(double time);
};

#endif // DISTANCECALCULATOR_H

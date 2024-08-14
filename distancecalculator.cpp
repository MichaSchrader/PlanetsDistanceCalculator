#include "distancecalculator.h"
#include "positions/positionofmercury.h"
#include "positions/positionofvenus.h"
#include "positions/positionofearth.h"
#include "positions/positionofmars.h"
#include "positions/positionofjupiter.h"
#include "positions/positionofsaturn.h"
#include "positions/positionofuranus.h"
#include "positions/positionofneptune.h"
#include <cmath>
#include <tuple>
DistanceCalculator::DistanceCalculator() {}

long long int DistanceCalculator::calculateDistance(std::string firstPlanet, std::string secondPlanet, long long julianDay)
{
    double time = (julianDay - 2451545.0) / 365250; // time in Julian millennia reckoned from J2000 (2000-Jan-01-Sat 12:00:00 TT)
    double firstX, firstY, firstZ;
    double secondX, secondY, secondZ;
    std::tie(firstX, firstY, firstZ) = DistanceCalculator::positionOfPlanet(firstPlanet, time);
    std::tie(secondX, secondY, secondZ) = DistanceCalculator::positionOfPlanet(secondPlanet, time);

    double differenceX = firstX - secondX;
    double differenceY = firstY - secondY;
    double differenceZ = firstZ - secondZ;
    return sqrt(differenceX*differenceX + differenceY*differenceY + differenceZ*differenceZ) * 149597870.691; // in kilometer
}

std::tuple<double, double, double> DistanceCalculator::positionOfPlanet(std::string planet, double time)
{
    double x, y, z;
    if (planet == "Sun")
        std::tie(x, y, z) = DistanceCalculator::positionOfSun(time);
    else if (planet == "Mercury")
        std::tie(x, y, z) = DistanceCalculator::positionOfMercury(time);
    else if (planet == "Venus")
        std::tie(x, y, z) = DistanceCalculator::positionOfVenus(time);
    else if (planet == "Earth")
        std::tie(x, y, z) = DistanceCalculator::positionOfEarth(time);
    else if (planet == "Mars")
        std::tie(x, y, z) = DistanceCalculator::positionOfMars(time);
    else if (planet == "Jupiter")
        std::tie(x, y, z) = DistanceCalculator::positionOfJupiter(time);
    else if (planet == "Saturn")
        std::tie(x, y, z) = DistanceCalculator::positionOfSaturn(time);
    else if (planet == "Uranus")
        std::tie(x, y, z) = DistanceCalculator::positionOfUranus(time);
    else if (planet == "Neptune")
        std::tie(x, y, z) = DistanceCalculator::positionOfNeptune(time);
    return std::make_tuple(x, y, z);
}

std::tuple<double, double, double> DistanceCalculator::positionOfSun(double t)
{
    return std::make_tuple(0, 0, 0);
}

std::tuple<double, double, double> DistanceCalculator::positionOfMercury(double t)
{
    double x = Mercury_A_X0(t) + Mercury_A_X1(t) + Mercury_A_X2(t) + Mercury_A_X3(t) + Mercury_A_X4(t) + Mercury_A_X5(t);
    double y = Mercury_A_Y0(t) + Mercury_A_Y1(t) + Mercury_A_Y2(t) + Mercury_A_Y3(t) + Mercury_A_Y4(t) + Mercury_A_Y5(t);
    double z = Mercury_A_Z0(t) + Mercury_A_Z1(t) + Mercury_A_Z2(t) + Mercury_A_Z3(t) + Mercury_A_Z4(t) + Mercury_A_Z5(t);
    return std::make_tuple(x, y, z);  // rectagular Heliocentric coordinates in AU
}

std::tuple<double, double, double> DistanceCalculator::positionOfVenus(double t)
{
    double x = Venus_A_X0(t) + Venus_A_X1(t) + Venus_A_X2(t) + Venus_A_X3(t) + Venus_A_X4(t) + Venus_A_X5(t);
    double y = Venus_A_Y0(t) + Venus_A_Y1(t) + Venus_A_Y2(t) + Venus_A_Y3(t) + Venus_A_Y4(t) + Venus_A_Y5(t);
    double z = Venus_A_Z0(t) + Venus_A_Z1(t) + Venus_A_Z2(t) + Venus_A_Z3(t) + Venus_A_Z4(t) + Venus_A_Z5(t);
    return std::make_tuple(x, y, z);  // rectagular Heliocentric coordinates in AU
}

std::tuple<double, double, double> DistanceCalculator::positionOfEarth(double t)
{
    double x = Earth_A_X0(t) + Earth_A_X1(t) + Earth_A_X2(t) + Earth_A_X3(t) + Earth_A_X4(t) + Earth_A_X5(t);
    double y = Earth_A_Y0(t) + Earth_A_Y1(t) + Earth_A_Y2(t) + Earth_A_Y3(t) + Earth_A_Y4(t) + Earth_A_Y5(t);
    double z = Earth_A_Z0(t) + Earth_A_Z1(t) + Earth_A_Z2(t) + Earth_A_Z3(t) + Earth_A_Z4(t) + Earth_A_Z5(t);
    return std::make_tuple(x, y, z);  // rectagular Heliocentric coordinates in AU
}

std::tuple<double, double, double> DistanceCalculator::positionOfMars(double t)
{
    double x = Mars_A_X0(t) + Mars_A_X1(t) + Mars_A_X2(t) + Mars_A_X3(t) + Mars_A_X4(t) + Mars_A_X5(t);
    double y = Mars_A_Y0(t) + Mars_A_Y1(t) + Mars_A_Y2(t) + Mars_A_Y3(t) + Mars_A_Y4(t) + Mars_A_Y5(t);
    double z = Mars_A_Z0(t) + Mars_A_Z1(t) + Mars_A_Z2(t) + Mars_A_Z3(t) + Mars_A_Z4(t) + Mars_A_Z5(t);
    return std::make_tuple(x, y, z);  // rectagular Heliocentric coordinates in AU
}

std::tuple<double, double, double> DistanceCalculator::positionOfJupiter(double t)
{
    double x = Jupiter_A_X0(t) + Jupiter_A_X1(t) + Jupiter_A_X2(t) + Jupiter_A_X3(t) + Jupiter_A_X4(t) + Jupiter_A_X5(t);
    double y = Jupiter_A_Y0(t) + Jupiter_A_Y1(t) + Jupiter_A_Y2(t) + Jupiter_A_Y3(t) + Jupiter_A_Y4(t) + Jupiter_A_Y5(t);
    double z = Jupiter_A_Z0(t) + Jupiter_A_Z1(t) + Jupiter_A_Z2(t) + Jupiter_A_Z3(t) + Jupiter_A_Z4(t) + Jupiter_A_Z5(t);
    return std::make_tuple(x, y, z);  // rectagular Heliocentric coordinates in AU
}

std::tuple<double, double, double> DistanceCalculator::positionOfSaturn(double t)
{
    double x = Saturn_A_X0(t) + Saturn_A_X1(t) + Saturn_A_X2(t) + Saturn_A_X3(t) + Saturn_A_X4(t) + Saturn_A_X5(t);
    double y = Saturn_A_Y0(t) + Saturn_A_Y1(t) + Saturn_A_Y2(t) + Saturn_A_Y3(t) + Saturn_A_Y4(t) + Saturn_A_Y5(t);
    double z = Saturn_A_Z0(t) + Saturn_A_Z1(t) + Saturn_A_Z2(t) + Saturn_A_Z3(t) + Saturn_A_Z4(t) + Saturn_A_Z5(t);
    return std::make_tuple(x, y, z);  // rectagular Heliocentric coordinates in AU
}

std::tuple<double, double, double> DistanceCalculator::positionOfUranus(double t)
{
    double x = Uranus_A_X0(t) + Uranus_A_X1(t) + Uranus_A_X2(t) + Uranus_A_X3(t) + Uranus_A_X4(t) + Uranus_A_X5(t);
    double y = Uranus_A_Y0(t) + Uranus_A_Y1(t) + Uranus_A_Y2(t) + Uranus_A_Y3(t) + Uranus_A_Y4(t) + Uranus_A_Y5(t);
    double z = Uranus_A_Z0(t) + Uranus_A_Z1(t) + Uranus_A_Z2(t) + Uranus_A_Z3(t) + Uranus_A_Z4(t) + Uranus_A_Z5(t);
    return std::make_tuple(x, y, z);  // rectagular Heliocentric coordinates in AU
}

std::tuple<double, double, double> DistanceCalculator::positionOfNeptune(double t)
{
    double x = Neptune_A_X0(t) + Neptune_A_X1(t) + Neptune_A_X2(t) + Neptune_A_X3(t) + Neptune_A_X4(t) + Neptune_A_X5(t);
    double y = Neptune_A_Y0(t) + Neptune_A_Y1(t) + Neptune_A_Y2(t) + Neptune_A_Y3(t) + Neptune_A_Y4(t) + Neptune_A_Y5(t);
    double z = Neptune_A_Z0(t) + Neptune_A_Z1(t) + Neptune_A_Z2(t) + Neptune_A_Z3(t) + Neptune_A_Z4(t) + Neptune_A_Z5(t);
    return std::make_tuple(x, y, z);  // rectagular Heliocentric coordinates in AU
}

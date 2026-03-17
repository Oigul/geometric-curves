#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

#include <iostream>
#include <memory>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <numeric>

/* + 1. создать enum для свитч кейсов*/

enum CurveType
{
    CircleType = 0,
    EllipseType = 1,
    HelixType = 2
};
const int N = 3; //кол-во кривых !!!oigul подумать про большее количество кривых

const int RMAX = 10;
const int STEPMAX = 5;


//2.
std::shared_ptr<Curve> createCurves(bool& hasCircle, bool& hasEllipse, bool& hasHelix)
{
    std::shared_ptr<Curve> curvePtr;

    int value = std::rand() % 3;
    switch (value)
    {
    case CircleType:
    {
        int r = std::rand() % RMAX + 1;
        curvePtr = std::make_shared<Circle>(r);
        hasCircle = true;
        break;
    }
    case EllipseType:
    {
        int rx = std::rand() % RMAX + 1;
        int ry = std::rand() % RMAX + 1;
        curvePtr = std::make_shared<Ellipse>(rx, ry);
        hasEllipse = true;
        break;
    }
    case HelixType:
    {
        int r = std::rand() % RMAX + 1;
        int step = std::rand() % STEPMAX + 1;
        curvePtr = std::make_shared<Helix>(r, step);
        hasHelix = true;
        break;
    }
    }

    //curvePtr = std::make_shared<Circle>(-5);

    return curvePtr;
}

void generateCurves(std::vector<std::shared_ptr<Curve>>& curves)
{
    bool hasCircle = false;
    bool hasEllipse = false;
    bool hasHelix = false;

    for (int i = 0; i < N; ++i)
    {
        std::shared_ptr<Curve> curvePtr;
        try
        {
           curvePtr = createCurves(hasCircle, hasEllipse, hasHelix);
        }
        catch (const std::invalid_argument& ex)
        {
            std::cout << "Error: " << ex.what() << std::endl;
            continue;
        }
        curves.push_back(curvePtr);
    }

    while (!hasCircle || !hasEllipse || !hasHelix)
    {
        std::shared_ptr<Curve> curvePtr;
        try
        {
            curvePtr = createCurves(hasCircle, hasEllipse, hasHelix);
        }
        catch (const std::invalid_argument& ex)
        {
            std::cout << "Error: " << ex.what() << std::endl;
            continue;
        }
        curves.push_back(curvePtr);
    }
}

//3.
void printCoordinates(const std::vector<std::shared_ptr<Curve>>& curves, double t)
{
    for (int i = 0; i < curves.size(); ++i) //какой size лучше !!!oigul
    {
        Point3D point3D = curves[i]->getPoint(t);
        Vector3D vector3D = curves[i]->getDerivative(t);

        std::cout << i << ". ";

        if (auto circle = std::dynamic_pointer_cast<Circle>(curves[i]))
            std::cout << "Circle " << " R = " << circle->getRadius() << std::endl;
        else if (auto ellipse = std::dynamic_pointer_cast<Ellipse>(curves[i]))
            std::cout << "Ellipse" << " Rx = " << ellipse->getRadiusX() << " Ry = " << ellipse->getRadiusY() << std::endl;
        else if (auto helix = std::dynamic_pointer_cast<Helix>(curves[i]))
            std::cout << "Helix" << " R = " << helix->getRadius() << " step = " << helix->getStep() << std::endl;

        std::cout << "Point3D "
            << point3D.m_x << " " << point3D.m_y << " "
            << point3D.m_z << std::endl;
        std::cout << "Vector3D "
            << vector3D.m_x << " " << vector3D.m_y << " "
            << vector3D.m_z << std::endl;
    }
}

//4.
std::vector<std::shared_ptr<Circle>> selectCircles(const std::vector<std::shared_ptr<Curve>>& curves)
{
    std::vector<std::shared_ptr<Circle>> circles;

    for (const std::shared_ptr<Curve>& curve : curves)
    {
        if (std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(curve))
            circles.push_back(circle);
    }
    return circles;
}

int main()
{
    std::vector<std::shared_ptr<Curve>> curves;

    std::srand(std::time(nullptr));
    generateCurves(curves);

    printCoordinates(curves, PI / 4);

    std::vector<std::shared_ptr<Circle>> circles = selectCircles(curves);
    std::cout << "circles size = " << circles.size() << std::endl;

    std::sort(circles.begin(), circles.end(),
        [](const std::shared_ptr<Circle>& c1, const std::shared_ptr<Circle>& c2)
        { return c1->getRadius() < c2->getRadius() ? true : false; }); //должен ли с1 стоять раньше с2

    double sum = std::accumulate(circles.begin(), circles.end(), 0.0,
        [](double sum, const std::shared_ptr<Circle>& c)
        { return sum + c->getRadius(); });
    std::cout << "sum = " << sum << std::endl;



    return 0;
}

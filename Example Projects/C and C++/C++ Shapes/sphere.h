#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include <string>

#include "shape.h"
#include "point.h"

using namespace std;

/*name: Daniel Han
date: 11/13/2023
description: header file for sphere.cpp, defines variables and methods
*/

class Sphere : public Shape{
    public:
        Sphere (string type, string color, Point center, double radius);

        double compute_volume (void);

    protected:

    private:
        Point center;
        double radius;
};



#endif

#include <string>
#include <iostream>

#include "sphere.h"
#include "shape.h"

using namespace std;

/*name: Daniel Han
date: 11/13/2023
description: implements methods defined in sphere.h
*/

Sphere::Sphere (string type, string color, Point center, double radius)
        : Shape (type, color, center){
    this -> color = color;
    this -> center = center;
    this -> radius = radius;
}

//Computes volume for sphere using standard equation
double Sphere::compute_volume(){
    return (4.0/ 3.0) * 3.14159 * (radius * radius * radius);
}
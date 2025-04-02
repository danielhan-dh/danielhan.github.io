#include <string>
#include <iostream>
#include <cmath>

#include "point.h"
#include "shape.h"

using namespace std;

/*name: Daniel Han
date: 11/13/2023
description:: defines methods length, operator, and print. Used in 
representing points in box, shape, cone, and sphere.
*/

double Point::length(){
    // double xVal = this -> x;
    // double yVal = this -> y;
    // double zVal = this -> z;
    return sqrt((x * x) + (y * y) + (z * z));
}

Point Point::operator- (Point& p){
    double x = this -> x - p.x;
    double y = this -> y - p.y;
    double z = this -> z - p.z;
    return Point(x, y, z);
}

void Point::print (void){
    cout << "Location: x: " << x << " y: " << y << " z: " << z; 
}


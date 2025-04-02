#include <string>
#include <iostream>

#include "box.h"
#include "shape.h"

using namespace std;

/*name: Daniel Han
date: 11/13/2023
description: implements methods from box.h.
*/

Box::Box(string type, string color, string tbcolor, double length, double width, double height, Point loc)
        : Shape (type, color, loc){
    this -> color = color;
    this -> tbcolor = tbcolor;
    this -> length = length;
    this -> width = width;
    this -> height = height;
}

//computing volume of a rectangular shape.
double Box::compute_volume(){
    return length * width * height;
}

void Box::print_color(){
    cout << "Side Color: " << color << "  Top/Base Color: " << tbcolor;
}


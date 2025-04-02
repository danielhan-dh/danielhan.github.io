#include <string>
#include <iostream>

#include "point.h"
#include "shape.h"

using namespace std;

/*name: Daniel Han
date: 11/13/2023
description: implements methods found in shape.h
*/

Shape::Shape(string type, string color, Point loc){
    this -> type = type;
    this -> color = color;
    this -> loc = loc;
}

void Shape::print_color (void){
    cout << "Color: "  << color;
}

void Shape::print_loc(void){
    cout << "Location: x: " << loc.x << " y: " << loc.y << " z: " << loc.z; 
    //this -> print_loc(); 
}

void Shape::print_type(void){
    cout << "Name: " << type;
}




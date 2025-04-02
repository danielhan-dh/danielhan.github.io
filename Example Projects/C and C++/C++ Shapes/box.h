#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <string>

#include "shape.h"
#include "point.h"

using namespace std;

/*name: Daniel Han
date: 11/13/2023
description: header file for box.h, defines methods and variables
*/

class Box : public Shape{
    public:
        Box(string type, string color, string tbcolor, double length, double width, double height, Point loc);

        void print_color(void);
    
        double compute_volume(void);

    protected:

    private:
        double length;
        double width;
        double height;
        string tbcolor;
};

#endif

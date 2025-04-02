#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

#include "point.h"

using namespace std;

/*name: Daniel Han
date: 11/13/2023
description: header file for shape.cpp, is the base class for box, cone, and sphere
*/

class Shape{
    private:
        string type;
        Point loc;

    protected:
        string color;

    public:
        Shape *next;

        Shape(string type, string color, Point loc);

        virtual void print_color(void);

        virtual double compute_volume(void) = 0;

        void print_type(void);

        void print_loc(void);
};


#endif

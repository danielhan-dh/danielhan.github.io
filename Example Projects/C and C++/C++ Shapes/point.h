#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

/*name: Daniel Han
date: 11/13/2023
description: header file for point.cpp, defines constructors, variables, and methods needed
*/

class Point{
    public:
        Point () {};
        
        Point (double x, double y, double z) { set (x, y, z); }

        inline void set  (double x, double y, double z){
            this -> x = x;
            this -> y = y;
            this -> z = z;
        }

        void print (void);

        Point operator- (Point& p);

        double length();

        double x;
        double y;
        double z;

    protected:

    private:
};

#endif

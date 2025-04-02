#include <string>
#include <iostream>

#include "cone.h"
#include "shape.h"
#include "point.h"
#include "box.h"
#include "sphere.h"

using namespace std;

/*name: Daniel Han
date: 11/13/2023
description: main file for project, takes user input in the form of a txt file,
then accesses the child classes to compute the volume of each shape and is then
output.
*/


void read_objs (Shape **list) {
   Shape *node;         // variable used to create a new node each time through the loop
   double x, y, z, xx, yy, zz, rad, length, width, height; // temporary variables used to read in values; fill in the rest
   string type, color, color2, tbcolor;     // temporary variables used to read in values; fill in the rest

   // initialize list
   *list = NULL;

   while (cin >> type) {

      if (type.compare ("sphere") == 0) {
        cin >> x >> y >> z >> rad >> color;

        node = new Sphere(type, color, Point(x, y, z), rad);
         // fill in code here to read in the sphere values and create a new node
      }

      else if (type.compare ("box") == 0) {
        cin >> length >> width >> height >> x >> y >> z >> color >> tbcolor;

        node = new Box(type, color, tbcolor, length, width, height, Point(x, y, z));
         // fill in code here to read in the box values and create a new node
      }
   
      else if (type.compare ("cone") == 0) {

         cin >> x >> y >> z >> xx >> yy >> zz >> rad >> color >> color2;

         node = new Cone (type, color, color2, Point (x, y, z), Point (xx, yy, zz), rad);
      }

      // link new node at front of list:
      node-> next = *list;
      *list = node;
      //   set the next field of node to the beginning of the list (*list)
      //   set the beginning of the list to node
   }
}

void print_objs(Shape *list){
    Shape *curr = list;
    while (curr != nullptr) {

        // Use the methods in Shape and its subclasses to print type, color, and loc
        curr -> print_type();
        cout << "\n";
        curr -> print_color();
        cout << "\n";
        curr -> print_loc();
        cout << "\n";
        // Print the volume computed by compute_volume
        cout << "Volume: " << curr -> compute_volume() << endl;
        cout << "\n";
        // Move to the next node in the list
        curr = curr -> next;
    }
}

int main () {
    Shape *list;
    read_objs (&list);
    print_objs (list);
    // add loop here to return any allocated space to the system

    Shape* iter = list;
    while(list -> next != NULL){
        iter = list;
        list = list -> next;
        delete iter;
    }
    return (0);
}



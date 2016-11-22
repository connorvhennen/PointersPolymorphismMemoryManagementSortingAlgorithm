/** @file Point2D.hpp
 @brief Declares a Point 2D class
 @author Connor Hennen
 @date October 26, 2016
 */

#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <vector>
#include <string>


/** @class Point2D
 @brief Describes a 2D point with two variables of type double
 
 This class has variables for the position of a 2D point, and a function for printing the point. It also contains overloaded operators for comparisons and functions that return the distance of the object from the origin, the type of point (represented numerically), the x- coordinate, and the y-coordinate.
 */
class Point2D{
public:
    
    //Constructor
    Point2D(double x, double y);
    
    //Print procedure
    virtual void print() const;
    
    //deconstructor
    virtual ~Point2D();

    //overloaded operator<
    virtual bool operator<(const Point2D& rhs) const;
    virtual bool operator==(const Point2D& rhs) const;

    double distance() const;
    virtual size_t pointType() const;
    
    //accessor functions
    virtual double get_x() const;
    virtual double get_y() const;
    
private:
    //variables
    double x;
    double y;
};

bool operator>=(const Point2D& a, const Point2D& b);
bool operator>(const Point2D& a, const Point2D& b);
bool operator<=(const Point2D& a, const Point2D& b);

#endif


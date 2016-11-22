/** @file Point2D.cpp
 @brief Implements a Point 2D class
 @author Connor Hennen
 @date October 26, 2016
 */

#include "Point2D.hpp"
#include <cmath>
#include <math.h>

const double PI = 3.14159265;
/** Constructor with two parameters
 @param init_x is the numeric value to be stored describing the point's position with respect to the x-axis
 @param init_y is the numeric value to be stored describing the point's position with respect to the y-axis
 */
Point2D::Point2D(double init_x, double init_y){
    x = init_x;
    y = init_y;
}

/** Prints the position of the point
 */
void Point2D::print() const{
    std::cout << "(" << x << "," << y << ")";
    
    return;
}

Point2D::~Point2D()
{}

//returns distance from origin
double Point2D::distance() const
{
    return sqrt(x*x + y*y);
}

//overloaded operator<
bool Point2D::operator<(const Point2D& rhs) const{
    if (distance() < rhs.distance()) {
        return true;
    }
    
    else
    {
    double angle = atan2(x,y);
    double rhsAngle = atan2(rhs.x, rhs.y);
    
    if (angle < 0) {
        angle = 2*PI + angle;
    }
    
    if (rhsAngle < 0) {
        rhsAngle = 2*PI + rhsAngle;
    }
    
    if (angle < rhsAngle) {
        return true;
    }
    
    else return false;
    }
}

//overloaded == operator
bool Point2D::operator==(const Point2D& rhs) const{
    double angle = atan2(x,y);
    double rhsAngle = atan2(rhs.x, rhs.y);
    
    if (angle < 0) {
        angle = 2*PI + angle;
    }
    
    if (rhsAngle < 0) {
        rhsAngle = 2*PI + rhsAngle;
    }
    
    if (angle == rhsAngle && distance() == rhs.distance()) {
        return true;
    }
    
    else return false;
}

//overloaded non-member <= operator
bool operator<=(const Point2D& lhs, const Point2D& rhs)
{
    return (lhs<rhs||lhs==rhs);
}

//overloaded non-member > operator
bool operator>(const Point2D& lhs, const Point2D& rhs)
{
    return !(lhs<=rhs);
}

//overloaded non-member >= operator
bool operator>=(const Point2D& lhs, const Point2D& rhs)
{
    return !(lhs<rhs);
}


//returns x coordinate of point
double Point2D::get_x() const{
    return x;
}


//returns y coordinate of point
double Point2D::get_y() const{
    return y;
}

// Returns the type of point: Point2D = 1, ColorPoint2D = 2, WeightedPoint2D = 3
size_t Point2D::pointType() const
{
    return 1;
}

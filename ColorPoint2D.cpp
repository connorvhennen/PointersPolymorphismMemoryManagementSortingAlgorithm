/** @file ColorPoint2D.cpp
 @brief Implements a ColorPoint2D class
 @author Connor Hennen
 @date October 26, 2016
 */

#include "ColorPoint2D.hpp"

#include <string>
#include <cmath>
#include <math.h>

const double PI = 3.14159265;
/** Constructor with three parameters
 
 @param init_x is the numeric value to be stored describing the point's position with respect to the x-axis. It will be implemented via the Point2D constructor and then initialized for a ColorPoint2D before the body of the ColorPoint2D constructor
 
 @param init_y is the numeric value to be stored describing the point's position with respect to the y-axis. It will be implemented via the Point2D constructor and then initialized for a ColorPoint2D before the body of the ColorPoint2D constructor
 
 @param init_color is the color value to be stored as a string
 */
ColorPoint2D::ColorPoint2D(double init_x, double init_y, std::string init_color):Point2D(init_x, init_y), color(init_color){}

/** Prints the color and then the position of the point. The position is printed via the Point2D class member print function
 */
void ColorPoint2D::print() const{
    std::cout<<color;
    Point2D::print();
    return;
}

ColorPoint2D::~ColorPoint2D()
{}

//operloaded operator< implementation
bool ColorPoint2D::operator==(const ColorPoint2D& rhs) const{
    
    double x = Point2D::get_x();
    double y = Point2D::get_y();
    
    double rhsX = rhs.Point2D::get_x();
    double rhsY = rhs.Point2D::get_y();
    
    double angle = atan2(x,y);
    double rhsAngle = atan2(rhsX, rhsY);
    
    if (angle < 0) {
        angle = 2*PI + angle;
    }
    
    if (rhsAngle < 0) {
        rhsAngle = 2*PI + rhsAngle;
    }
    
    if (angle == rhsAngle && color == rhs.color && distance() == rhs.distance()) {
        return true;
    }
    
    else{
        return false;
    }
}

//operloaded operator< implementation
bool ColorPoint2D::operator<(const ColorPoint2D& rhs) const{
    
    if(distance() < rhs.distance()) {
        return true;
    }
    
    else{
    double x = Point2D::get_x();
    double y = Point2D::get_y();
    
    double rhsX = rhs.Point2D::get_x();
    double rhsY = rhs.Point2D::get_y();
    
    double angle = atan2(x,y);
    double rhsAngle = atan2(rhsX, rhsY);
    
    if (angle < 0) {
        angle = 2*PI + angle;
    }
    
    if (rhsAngle < 0) {
        rhsAngle = 2*PI + rhsAngle;
    }
    
    if (angle < rhsAngle) {
        return true;
    }
    
    else if (angle == rhsAngle){
        if (color < rhs.color) {
            return true;
        }
        else return false;
        
    }
    
    else{
        return false;
    }
    }
}

// Returns the type of point: Point2D = 1, ColorPoint2D = 2, WeightedPoint2D = 3
size_t ColorPoint2D::pointType() const
{
    return 2;
}

//overloaded non-member operator <=
bool operator<=(const ColorPoint2D& lhs, const ColorPoint2D& rhs)
{
    return (lhs<rhs)||(lhs==rhs);
}

//overloaded non-member operator >
bool operator>(const ColorPoint2D& lhs, const ColorPoint2D& rhs)
{
    return !(lhs<=rhs);
}

//overloaded non-member operator >=
bool operator>=(const ColorPoint2D& lhs, const ColorPoint2D& rhs)
{
    return !(lhs<rhs);
}



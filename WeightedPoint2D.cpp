/** @file WeightedPoint2D.cpp
 @brief Implements a WeightedPoint2D class
 @author Connor Hennen
 @date October 26, 2016
 */

#include "WeightedPoint2D.hpp"

#include <string>
#include <cmath>
#include <math.h>

const double PI = 3.14159265;
/** Constructor with three parameters
 
 @param init_x is the numeric value to be stored describing the point's position with respect to the x-axis. It will be implemented via the Point2D constructor and then initialized for a ColorPoint2D before the body of the ColorPoint2D constructor
 
 @param init_y is the numeric value to be stored describing the point's position with respect to the y-axis. It will be implemented via the Point2D constructor and then initialized for a ColorPoint2D before the body of the ColorPoint2D constructor
 
 @param init_weight is the weight value to be stored as a double
 */
WeightedPoint2D::WeightedPoint2D(double init_x, double init_y, double init_weight):Point2D(init_x, init_y), weight(init_weight){}

/** Prints the weight and then the position of the point. The position is printed via the Point2D class member print function
 */
void WeightedPoint2D::print() const{
    std::cout<<weight;
    Point2D::print();
    return;
}

WeightedPoint2D::~WeightedPoint2D()
{}

//operloaded operator< for comparison with WeightedPoint2D implementation
bool WeightedPoint2D::operator<(const WeightedPoint2D& rhs) const{
    
    if (distance() < rhs.distance()) {
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
        if (weight < rhs.weight) {
            return true;
        }
        else return false;
        
    }
    
    else{
        return false;
    }
    }
}

//operloaded operator== implementation
bool WeightedPoint2D::operator==(const WeightedPoint2D& rhs) const{
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
    
    if (angle == rhsAngle && weight == rhs.weight && distance() == rhs.distance()) {
        return true;
    }
    
    else{
        return false;
    }
}

//overloaded non-member operator<=
bool operator<=(const WeightedPoint2D& lhs, const WeightedPoint2D& rhs)
{
    return (lhs<rhs)||(lhs==rhs);
}

//overloaded non-member operator<
bool operator>(const WeightedPoint2D& lhs, const WeightedPoint2D& rhs)
{
    return !(lhs<=rhs);
}

//overloaded non-member operator>=
bool operator>=(const WeightedPoint2D& lhs, const WeightedPoint2D& rhs)
{
    return !(lhs<rhs);
}

// Returns the type of point: Point2D = 1, ColorPoint2D = 2, WeightedPoint2D = 3
size_t WeightedPoint2D::pointType() const
{
    return 3;
}



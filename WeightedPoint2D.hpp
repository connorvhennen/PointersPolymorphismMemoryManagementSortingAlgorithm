/** @file WeightedPoint2D.hpp
 @brief Declares a WeightedPoint2D class
 @author Connor Hennen
 @date October 26, 2016
 */

#include <iostream>
#include <vector>
#include <string>

#ifndef WEIGHTEDPOINT2D_H
#define WEIGHTEDPOINT2D_H

#include "Point2D.hpp"
#include "ColorPoint2D.hpp"

/** @class WeightedPoint2D
 @brief Describes the position of a 2D point with three variables of type double
 
 This class is designed to inherit the properties of the Point2D class, and contain an additional property that describes the point's weight. It contains inherited variables for the position of a 2D point, its own variable for the weight, and its own print function, which accesses the print function of the base Point2D class. It also contains overloaded operators for comparisons and a function that returns the type of point, represented numerically
 */

class WeightedPoint2D:public Point2D {
public:
    
    //Constructor
    WeightedPoint2D(double init_x, double init_y, double init_weight);
    
    //Print procedure
    virtual void print() const;
    
    //deconstructor
    virtual ~WeightedPoint2D();
    
    virtual size_t pointType() const;
    
    virtual bool operator<(const WeightedPoint2D& input) const;
    virtual bool operator==(const WeightedPoint2D& input) const;
    
private:
    
    // Weight variable
    double weight;
};

bool operator>=(const WeightedPoint2D& a, const WeightedPoint2D& b);
bool operator>(const WeightedPoint2D& a, const WeightedPoint2D& b);
bool operator<=(const WeightedPoint2D& a, const WeightedPoint2D& b);

#endif

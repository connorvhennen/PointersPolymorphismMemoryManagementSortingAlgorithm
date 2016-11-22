/** @file ColorPoint2D.hpp
 @brief Declares a ColorPoint2D class
 @author Connor Hennen
 @date October 26, 2016
 */

#include <iostream>
#include <vector>
#include <string>

#ifndef COLORPOINT2D_H
#define COLORPOINT2D_H

#include "Point2D.hpp"

/** @class ColorPoint2D
 @brief Describes the position of a 2D point with two variables of type double, and the color of the point with a variable of type string
 
 This class is designed to inherit the properties of the Point2D class, and contain an additional property that describes the point's color. It contains inherited variables for the position of a 2D point, its own variable for the color of a 2D, and its own print function, which accesses the print function of the base Point2D class. It also contains overloaded operators for comparisons and a function that returns the type of point, represented numerically
 */

class ColorPoint2D:public Point2D {
public:
    
    //Constructor
    ColorPoint2D(double init_x, double init_y, std::string init_color);
    
    //Print procedure
    virtual void print() const;

    //deconstructor
    virtual ~ColorPoint2D();
    
    //overloaded operator<
    virtual bool operator<(const ColorPoint2D& rhs) const;
    
    //overloaded operator==
    virtual bool operator==(const ColorPoint2D& rhs) const;

    virtual size_t pointType() const;
    
private:
    
    // Color variable
    std::string color;
};

bool operator>=(const ColorPoint2D& lhs, const ColorPoint2D& rhs);
bool operator>(const ColorPoint2D& lhs, const ColorPoint2D& rhs);
bool operator<=(const ColorPoint2D& lhs, const ColorPoint2D& rhs);


#endif

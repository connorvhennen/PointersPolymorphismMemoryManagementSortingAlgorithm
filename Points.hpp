/** @file Points.hpp
 @brief Declares a Points class
 @author Connor Hennen
 @date October 26, 2016
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


#ifndef POINTS_H
#define POINTS_H


#include "Point2D.hpp"
#include "ColorPoint2D.hpp"
#include "WeightedPoint2D.hpp"

/** @class Points
 @brief This class can store pointers to Point2D, ColorPoint2D, and WeightedPointed2D objects, and manages memory automatically
 
 This class is designed to pointers of type Point2D, which can point to objects of type Point2D, ColorPoint2D, and WeightedPoint2D. The class has a function that will push back Point2D pointers to a vector, a variable for this vector, and a destructor which will delete all of a Points class object's contents when the object is out of scope
 */

class Points{
public:
    void push_back(Point2D* pt);
    
    virtual ~Points();
    
    virtual void print() const;
    
    void sortAlgorithm();
    
    size_t getSize() const;
    
private:
    std::vector<Point2D*> points;
};

#endif

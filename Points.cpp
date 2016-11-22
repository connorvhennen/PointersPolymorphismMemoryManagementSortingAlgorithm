/** @file Points.cpp
 @brief Implements a Points class
 @author Connor Hennen
 @date October 26, 2016
 */


#include "Points.hpp"
#include <algorithm>
#include <vector>

void Points::push_back(Point2D* pt){
    points.push_back(pt);
}

Points::~Points(){
    for(auto& x : points){
        delete x;
    }
}

void Points::print() const{
    for (size_t i = 0, n = points.size(), numberOfSelections = 1; i < n; ++i, ++numberOfSelections) {
        
        std::cout << numberOfSelections << ": ";
        
        points[i] -> print();
        
        std::cout << std::endl;
    }
}

/** @function lessThan
 @brief Compares points of type Point2D, ColorPoint2D, and WeightedPoint2D
 
 @param lhs is a Point2D* pointer which points to an object of type Point2D, ColorPoint2D, or WeightedPoint2D
 
 @param rhs is a Point2D* pointer which points to an object of type Point2D, ColorPoint2D, or WeightedPoint2D
 
 @returns true if the point is considered less and false if otherwise based on these criteria: from least to greatest- Point2D, ColorPoint2D, WeightedPoint2D. Tiebreakers decided by distance from origin, angle going counterclockwise from origin, lexicographic ordering of color, and weight.
 */
bool lessThan(Point2D* lhs, Point2D* rhs)
{
    if (lhs->pointType() != rhs->pointType())
    {
        if(lhs->pointType() < rhs->pointType()) return true;
        else return false;
    }
    else if (lhs->pointType() == 1)
    {
        if (*lhs < *rhs) return true;
        else return false;
    }
    else if (lhs->pointType() == 2)
    {
        ColorPoint2D* lhsColorPoint = dynamic_cast<ColorPoint2D*>(lhs);
        ColorPoint2D* rhsColorPoint = dynamic_cast<ColorPoint2D*>(rhs);
            
        if (*lhsColorPoint < *rhsColorPoint) return true;
        else return false;
    }
    else
    {
        WeightedPoint2D* lhsWeightedPoint = dynamic_cast<WeightedPoint2D*>(lhs);
        WeightedPoint2D* rhsWeightedPoint = dynamic_cast<WeightedPoint2D*>(rhs);
            
        if (*lhsWeightedPoint < *rhsWeightedPoint) return true;
        else return false;
        }
    }

//sorts using std::sort function with the LessThan comparison
void Points::sortAlgorithm()
{
    std::sort(points.begin(), points.end(), lessThan);
}

//returns length of points vector
size_t Points::getSize() const
{
    return points.size();
}

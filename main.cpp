/** @file main.cpp
 @brief In this file a user can create objects of type Point2D, ColorPoint2D and WeightedPoint2D, and then the created objects are displayed in order
 @author Connor Hennen
 @date October 26, 2016
 */


#include <string.h>
#include <vector>
#include <iostream>

#include "Points.hpp"

/** @function storePointOutputInput
 @brief Stores the user defined point via a Point2D pointer pushed back to a Points object vector, and prints the user inputs as they go along
 
 @param &pointer is the Points object that will store the pointer
 @param pointSelection is the type of point that the user wishes to create
 
 */
void storePointDisplayInput(Points &pointer, int pointSelection);

/** @function main
@brief Prompts user to create objects of type Point2D, ColorPoint2D and WeightedPoint2D, and then outputs the created objects
@author Connor Hennen
@date October 26, 2016
 
 The main function will introduce the user to the object types available and then creates as many of these objects as the user wants, displaying the user input as they go along and finally outputting all of the created objects when the user has finished. The main function utilizing polymorphism, while managing memory through the Resource Acquisition is Initialization technique. In particular, the user created objects are stored via Point2D pointers pushed back to a Points object vector, where the pointers can point to objects of all the available types (polymorphism), and are deconstructed automatically. Before printing the vector will be sorted in the order of WeightedPoint2D first, ColorPoint2D second, and Point2D last. Tiebreakers will be determined first by the distance from the origin, and then by the angle going counterclockwise from the origin, and then if necessary, for ColorPoint2D, by the points' colors in lexicographic ordering, and for WeightedPoint2D, by the points' weight.
 */

int main(){
    
    int pointSelection = 1;
    std::string colorInput;
    
    Points inputPoints;
    
    std::cout<< "Welcome to Point Printer!  You can create three different kinds of points:" << std::endl << std::endl;
    
    std::cout<< "1.  Point2D, e.g., (2,6.5)" << std::endl;
    std::cout<< "2.  ColorPoint2D, e.g., blue(-4.5,3.5)" << std::endl;
    std::cout<< "3.  WeightedPoint2D, e.g., .12(3,8.7)" << std::endl << std::endl;
    
    std::cout<< "Enter 0 when you are finished." << std::endl << std::endl;
    
    while (pointSelection != 0) {
        std::cout<< "Selection: ";
        std::cin>> pointSelection;
        
        storePointDisplayInput(inputPoints, pointSelection);
    }
    
    std::cout << std::endl << "Your points in sorted order are: " << std::endl << std::endl;
        inputPoints.sortAlgorithm();
        inputPoints.print();
        std::cout << std::endl;
    
    return 0;
}

// definition of storeSelection function
void storePointDisplayInput(Points &pointer, int pointInput){
    
    double xCoordinateInput = 0;
    double yCoordinateInput = 0;
    double weightInput = 0;
    std::string colorInput;
    
    
    //if user selected class Point2D, pushes back a point2D pointer (that points to a Point2D object with user input values) to a Points vector
    if (pointInput== 1) {
        
        std::cout << "x: ";
        std::cin>> xCoordinateInput;
        std::cout << "y: ";
        std::cin>> yCoordinateInput;
        
        pointer.push_back(new Point2D(xCoordinateInput,yCoordinateInput));
    }
    
    //if user selected class ColorPoint2D, pushes back a point2D pointer (that points to a ColorPoint2D object with user input values) to the points object vector
    if (pointInput == 2) {
        
        std::cout << "x: ";
        std::cin>> xCoordinateInput;
        std::cout << "y: ";
        std::cin>> yCoordinateInput;
        std::cout << "color: ";
        std::cin.ignore();
        std::getline(std::cin,colorInput);
        
        pointer.push_back(new ColorPoint2D(xCoordinateInput,yCoordinateInput, colorInput));
        }
        
        //if user selected class WeightedPoint2D, pushes back a WeightetPoint2D pointer (that points to a ColorPoint2D object with user input values) to the points object vector
    if (pointInput == 3) {
            
        std::cout << "x: ";
        std::cin>> xCoordinateInput;
        std::cout << "y: ";
        std::cin>> yCoordinateInput;
        std::cout << "weight: ";
        std::cin>> weightInput;
            
        pointer.push_back(new WeightedPoint2D(xCoordinateInput,yCoordinateInput, weightInput));
        }
    }


/****************************************************************************
Name: Helper.cpp
Author: Kevin Benoit
Date: 4/22/2020
Description: Set of helper functions for file IO, string maninuplaction, ect. 
Will expand with more functions as class continues.
Citations:
Substrings:
http://www.cplusplus.com/reference/string/string/substr/
stoi:
http://www.cplusplus.com/reference/string/stoi/
rand/srand:
https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
string.find()
http://www.cplusplus.com/reference/string/string/find/
****************************************************************************/
#include "Helper.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

/***************************************************************************
Description: Function to take line of numbers and store as integers in vector
Accepts: any string of integers separated by a space ' '
    An empty vector passed by reference
****************************************************************************/
void Helper::transform_string(std::string stringIn, std::vector<int> &v) {
    int cursor = 0;
    int i = 0; //keep track of substrings beginning
    //go until end of line
    while (cursor < static_cast<int>(stringIn.length())) {
        if (stringIn[cursor] != ' ') {
            int j = 1;
            //check for either end of int or end of line
            while (stringIn[cursor] != ' ' && stringIn[cursor] != '\0') {
                cursor++;
                j++;
            }
            //add this substring, converted to integer, to vector
            v.push_back(std::stoi(stringIn.substr(i, j)));
            i += j;
        }
        //skip over the space
        else cursor++;
    }
}

/****************************************************************************
Description: Prints the integer values stored in a vector
Accepts: A vector filled with ints
****************************************************************************/
void Helper::print_vector(std::vector<int> v) {
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        std::cout << v.at(i) << " ";
    }

    std::cout << std::endl;
}

/******************************************************************************
Description: Generate random numbers of size_n from 0 to size_n
Accepts: upper bound on on size_n
Returns: integer vector of size n
******************************************************************************/
std::vector<int> Helper::generate_random_ints(int size_n) {
    srand(time(0));//set the seed at time(0)

    std::vector<int> random_ints;
    for (int i = 0; i < size_n; i++) {
        random_ints.push_back(rand() % size_n); //push a random number from 0 to size_n
    }

    return random_ints;
}

/******************************************************************************
Description: Convert a string fraction to a floating point number
Accepts: string fraction
Returns: float equivalent
******************************************************************************/
float Helper::fraction_to_float(std::string fraction) {
	//a whole number, return as float
	if (fraction.find('/') == std::string::npos) {
		return (float)std::stoi(fraction);
	}

	else {
		//get position of divisor
		int divider = fraction.find('/');

		//get numerator and denominator as ints
		int numerator = std::stoi(fraction.substr(0, divider));
		int denominator = std::stoi(fraction.substr(divider+1));

		//return the fraction's decimal equivalent
		return float(numerator)/(float)denominator;
	}
}

/*
Transform room name from its integer representation to a string
*/
std::string Helper::getRoomNameFromNumber(int roomNumber) {
	switch (roomNumber) {
	case(0):
		return "hallway";
	case(1):
		return "kitchen";
	case(2):
		return "ballroom";
	case(3):
		return "conservatory";
	case(4):
		return "billard room";
	case(5):
		return "dining room";
	case(6):
		return "library";
	case(7):
		return "hall";
	case(8):
		return "lounge";
	case(9):
		return "study";
	default:
		throw "roomNumber out of range";
	}
}
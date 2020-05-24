/****************************************************************************
Name:Helper.hpp
Author: Kevin Benoit
Date: 4/22/2020
Description: Set of helper functions for file IO, string maninuplaction, ect. Will expand as class continues
Citations:
Format of Helper files/class:
CS 162 Group Project, Steven Ochoa
****************************************************************************/

#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>
#include <vector>

class Helper {
    public:
        static void transform_string(std::string stringIn, std::vector<int> &v);
        static void print_vector(std::vector<int> v);
        static std::vector<int> generate_random_ints(int size_n);
		static float fraction_to_float(std::string fraction);
		static std::string getRoomNameFromNumber(int roomNumber);
};
#endif
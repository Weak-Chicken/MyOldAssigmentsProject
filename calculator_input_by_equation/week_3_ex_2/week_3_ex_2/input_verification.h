/*
@author: Yucheng Xie  ID:201138727
Date: 11/9/2016

Copyright © 2016 Yucheng Xie. All rights reserved.
This code can be copied and modified for academic purposes. Including demonstration and reuse in other cases for academic
purposes. However, this code should not be used for commercial purposes.
*/
#pragma once

#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::boolalpha;

template <typename T> size_t get_length_of_array(T& array)
{
	size_t a = sizeof(array);
	size_t b = sizeof(array[0]);
	return (sizeof(array) / sizeof(array[0]));
}

//This function will test the input string format. 
//If input string is an integer, it will return true. Otherwise return false.
bool input_verification(string Input, int &container_of_int);

//This function will test the input string format.
//If input string is a double number, it will return true. Otherwise return false.
bool input_verification(string Input, double &container_of_double);

//This function will test the input string format.
//If input string is a float number, it will return true. Otherwise return false.
bool input_verification(string Input, float &container_of_float);

//This function will test the input string format.
//If input string is a bool value, it will return true. Otherwise return false.
bool input_verification(string Input, bool &container_of_bool);


//This function will test the input string format and range.
//If input string is an integer and in the range [min,max], it will return true. Otherwise return false.
bool input_verification_in_range(string Input, int &container_of_int, int min, int max);

//This function will test the input string format and range.
//If input string is a double number and in the range [min,max], it will return true. Otherwise return false.
bool input_verification_in_range(string Input, double &container_of_double, double min, double max);

//This function will test the input string format and range.
//If input string is a float number and in the range [min,max], it will return true. Otherwise return false.
bool input_verification_in_range(string Input, float &container_of_float, float min, float max);

//This function will test the input string format and range.
//If input string is an integer and in the range [min,max], it will return the value of the integer.
//Otherwise it will ask reinput until the user input right number.
int input_verification_in_range_with_display(string Input, int min, int max);

//This function will test the input string format and range.
//If input string is a double number and in the range [min,max], it will return the value of the double number.
//Otherwise it will ask reinput until the user input right number.
double input_verification_in_range_with_display(string Input, double min, double max);

//This function will test the input string format and range.
//If input string is a float numbner and in the range [min,max], it will return the value of the float.
//Otherwise it will ask reinput until the user input right number.
float input_verification_in_range_with_display(string Input, float min, float max);

bool input_verification_string_contain(string Input, string Find_these_chars);

bool input_verification_string_only_contain(string Input, string Find_these_chars);

int input_verification_string_find_first_traget(string Input, string Find_these_chars);
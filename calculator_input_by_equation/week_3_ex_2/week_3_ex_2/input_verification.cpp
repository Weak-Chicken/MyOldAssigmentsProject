/*
@author: Yucheng Xie  ID:201138727
Date: 11/9/2016

Copyright © 2016 Yucheng Xie. All rights reserved.
This code can be copied and modified for academic purposes. Including demonstration and reuse in other cases for academic
purposes. However, this code should not be used for commercial purposes.
*/
#include "input_verification.h"

bool input_verification(string Input, int & container_of_int)
{
	stringstream input_temp;
	string verification_temp;

	//Set the precision of the stringstream
	input_temp.precision(15);

	input_temp << Input;
	input_temp >> container_of_int;
	input_temp.str("");
	input_temp.clear();
	input_temp << container_of_int;
	input_temp >> verification_temp;
	//If the two strings are the same, means the input string is at right format
	if (Input == verification_temp) {
		return true;
	}
	else {
		return false;
	}
}

bool input_verification(string Input, double & container_of_double)
{
	stringstream input_temp;
	string verification_temp;

	//Set the precision of the stringstream
	input_temp.precision(15);

	input_temp << Input;
	input_temp >> container_of_double;
	input_temp.str("");
	input_temp.clear();
	input_temp << container_of_double;
	input_temp >> verification_temp;
	//If the two strings are the same, means the input string is at right format.
	//Here remove the last character is because double type will round itself when translation
	if (Input.length() > 1) {
		Input = Input.substr(0, verification_temp.length() - 1);
		verification_temp = verification_temp.substr(0, verification_temp.length() - 1);
	}

	if (Input == verification_temp) {
		return true;
	}
	else {
		return false;
	}
}

bool input_verification(string Input, float & container_of_float)
{
	stringstream input_temp;
	string verification_temp;

	//Set the precision of the stringstream
	input_temp.precision(7);

	input_temp << Input;
	input_temp >> container_of_float;
	input_temp.str("");
	input_temp.clear();
	input_temp << container_of_float;
	input_temp >> verification_temp;
	//If the two strings are the same, means the input string is at right format.
	//Here remove the last character is because float type will round itself when translation
	if (Input.length() > 1) {
		Input = Input.substr(0, verification_temp.length() - 1);
		verification_temp = verification_temp.substr(0, verification_temp.length() - 1);
	}

	if (Input == verification_temp) {
		return true;
	}
	else {
		return false;
	}
}

bool input_verification(string Input, bool & container_of_bool)
{
	stringstream input_temp;
	string verification_temp;

	input_temp << Input;
	input_temp >> boolalpha >> container_of_bool;
	input_temp.str("");
	input_temp.clear();
	input_temp << container_of_bool;
	input_temp >> boolalpha >> verification_temp;
	if (Input == verification_temp) {
		return true;
	}
	else {
		return false;
	}
}

bool input_verification_in_range(string Input, int & container_of_int, int min, int max)
{
	if (input_verification(Input, container_of_int)) {
		if (container_of_int >= min && container_of_int <= max) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool input_verification_in_range(string Input, double & container_of_double, double min, double max)
{
	if (input_verification(Input, container_of_double)) {
		if (container_of_double >= min && container_of_double <= max) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool input_verification_in_range(string Input, float & container_of_float, float min, float max)
{
	if (input_verification(Input, container_of_float)) {
		if (container_of_float >= min && container_of_float <= max) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int input_verification_in_range_with_display(string Input, int min, int max)
{
	int verified_number;
	while (!input_verification(Input, verified_number)) {
		cout << "Please input an integer!" << endl;
		cin >> Input;
	}
	//The function will not stop until user input right format value in the range.
	while (!((verified_number >= min) && (verified_number <= max))) {
		cout << "Please input an integer in the range of " << min << " and " << max << endl;
		cin >> Input;
		while (!input_verification(Input, verified_number)) {
			cout << "Please input an integer!" << endl;
			cin >> Input;
		}
	}

	return verified_number;
}

double input_verification_in_range_with_display(string Input, double min, double max)
{
	double verified_number;
	while (!input_verification(Input, verified_number)) {
		cout << "Please input a double number!" << endl;
		cin >> Input;
	}
	//The function will not stop until user input right format value in the range.
	while (!((verified_number >= min) && (verified_number <= max))) {
		cout << "Please input a double number in the range of " << min << " and " << max << endl;
		cin >> Input;
		while (!input_verification(Input, verified_number)) {
			cout << "Please input a double number!" << endl;
			cin >> Input;
		}
	}

	return verified_number;
}

float input_verification_in_range_with_display(string Input, float min, float max)
{
	float verified_number;
	while (!input_verification(Input, verified_number)) {
		cout << "Please input a float number!" << endl;
		cin >> Input;
	}
	//The function will not stop until user input right format value in the range.
	while (!((verified_number >= min) && (verified_number <= max))) {
		cout << "Please input a float number in the range of " << min << " and " << max << endl;
		cin >> Input;
		while (!input_verification(Input, verified_number)) {
			cout << "Please input a float number!" << endl;
			cin >> Input;
		}
	}

	return verified_number;
}

bool input_verification_string_contain(string Input, string Find_these_chars)
{
	//int a[] = {1,2,3,4,5,6,7,8,9,0};
	//size_t length_of_array{ _countof(Find_these_chars) };

	//size_t length = get_length_of_array(Find_these_chars);

	for (int i = 0;i < Input.length();i++) {
		for (int j = 0;j < Find_these_chars.length();j++) {
			if (Input[i] == Find_these_chars[j]) {
				return true;
			}
		}
	}

	return false;
}

bool input_verification_string_only_contain(string Input, string Find_these_chars)
{
	for (int i = 0;i < Find_these_chars.length();i++) {
		for (int j = 0;j < Input.length();j++) {
			if (Find_these_chars[i] == Input[j]) {
				for (int k = j;k < Input.length();k++) {
					Input[k] = Input[k + 1];
				}
				j--;
				Input = Input.substr(0, Input.length() - 1);
			}
		}
	}

	if (Input.length() == 0) {
		return true;
	}
	else {
		return false;
	}
}

int input_verification_string_find_first_traget(string Input, string Find_these_chars)
{
	for (int i = 0;i < Input.length();i++) {
		for (int j = 0;j < Find_these_chars.length();j++) {
			if (Input[i] == Find_these_chars[j]) {
				return i;
			}
		}
	}
	return -1;
}

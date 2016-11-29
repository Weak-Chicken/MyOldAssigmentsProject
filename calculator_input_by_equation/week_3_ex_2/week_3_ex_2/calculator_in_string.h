/*
This library need library "input_verification", which is available at https://github.com/Weak-Chicken/MyCleverLibrariesCPP
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include "input_verification.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;
using std::boolalpha;

class calculator_in_string
{
private:
	string equation;
	string allow_chars = "+-*/%^1234567890 .()";
	string operators = "+-*%/^()";
	vector <string>stack_eq;
	vector <string>stack_op;
	vector <string>stack_cal;
	vector <string>stack_temp;
	double result = 0;

	void translate_to_postfix();
	void calculate_postfix();
	double operate_to_numbers(double Num1, double Num2, char Op);
	bool is_an_operator(char Now_char);

	int compare_two_operators(char Op1, char Op2);

public:
	calculator_in_string() { cout << "Please input your equation(only use operation +,-,*,/,%,^,(,)):";cin >> equation; };
	calculator_in_string(string Equation) :equation(Equation) {};
	~calculator_in_string() {};

	double get_results() { return result; };

	void calculate();
};


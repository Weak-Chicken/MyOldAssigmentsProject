#include "calculator_in_string.h"

void calculator_in_string::translate_to_postfix()
{
	string temp_number = "NULL";
	int operator_position = 0;
	int pointer = 0;
	double operate_num = 0;

	while (!input_verification_string_only_contain(equation, allow_chars)) {
		cout << "Please input only numbers and +,-,*,/,%,^,(,)!\n";
		cin >> equation;
	}
	string equation_copy = equation;

	while (pointer < equation.size()) {
		//operator_position = input_verification_string_find_first_traget(equation_copy, operators);
		//temp_number = equation_copy.substr(0, operator_position);
		//if (equation_copy[0] != '(') {
		//	if (!input_verification(equation_copy.substr(0, operator_position), operate_num)) {
		//		while (!input_verification(temp_number, operate_num)) {
		//			cout << "Please check your equation, there should be a number missing or space between number and operators!\n";
		//			cout << "Please reinput your number before operator " << equation_copy[operator_position] << " :";
		//			cin >> temp_number;
		//		}
		//	}
		//	stack_eq.push_back(temp_number);
		//	for (int i = stack_op.size() - 1;i >= 0;i--) {
		//		if (compare_two_operators(equation_copy[operator_position], stack_op[i][0]) == 0) {
		//			stack_eq.push_back(stack_op[i]);
		//			stack_op.pop_back();
		//		}
		//		else {
		//			stack_op.push_back(equation_copy.substr(operator_position, 1));
		//			break;
		//		}
		//	}
		//	equation_copy = equation_copy.substr(operator_position);
		//}
		//else {
		//	stack_op.push_back(equation_copy.substr(0, 1));
		//	equation_copy = equation_copy.substr(1);
		//}

		//================================================================================================================
		if (!is_an_operator(equation_copy[pointer])) {
			stack_eq.push_back(equation_copy.substr(pointer, 1));
			pointer++;
		}
		else {
			if (equation_copy[pointer] == '(') {
				stack_op.push_back(equation_copy.substr(pointer, 1));
				pointer++;
			}
			else {
				if (equation_copy[pointer] == ')') {
					while (stack_op.back()[0] != '(') {
						stack_eq.push_back(stack_op.back());
						stack_op.pop_back();
					}
					stack_op.pop_back();
					pointer++;
				}
				else {
					if (stack_op.size() == 0) {
						stack_op.push_back(equation_copy.substr(pointer, 1));
						pointer++;
					}
					else {
						while (compare_two_operators(equation_copy[pointer], stack_op.back()[0]) == 0 && stack_op.size() != 0) {
							stack_eq.push_back(stack_op.back());
							stack_op.pop_back();
						}
						stack_op.push_back(equation_copy.substr(pointer,1));
						pointer++;
					}
				}
			}
		}
	}
	while (stack_op.size() > 0) {
		stack_eq.push_back(stack_op.back());
		stack_op.pop_back();
	}
}

void calculator_in_string::calculate_postfix()
{
	for (int i = stack_eq.size() - 1;i >= 0;i--) {
		stack_cal.push_back(stack_eq[i]);
	}
	while (stack_cal.size() != 0) {
		if (!is_an_operator(stack_cal.back()[0])) {
			stack_temp.push_back(stack_cal.back());
			stack_cal.pop_back();
		}
		else {
			double temp_1 = 0;
			double temp_2 = 0;
			input_verification(stack_temp.back(), temp_2);
			stack_temp.pop_back();
			input_verification(stack_temp.back(), temp_1);
			stack_temp.pop_back();
			double temp_result = operate_to_numbers(temp_1, temp_2, stack_cal.back()[0]);

			stringstream input_temp;
			string string_temp;
			input_temp.precision(15);

			input_temp << temp_result;
			input_temp >> string_temp;

			stack_temp.push_back(string_temp);
			stack_cal.pop_back();
		}
	}

	if (stack_temp.size() == 1) {
		double temp_1 = 0;
		input_verification(stack_temp.back(), temp_1);
		result = temp_1;
	}
	else {
		cout << "Error in calculation! check your equation!";
	}
}

double calculator_in_string::operate_to_numbers(double Num1, double Num2, char Op)
{
	switch (Op)
	{
	case '+':
		return Num1 + Num2;
		break;
	case '-':
		return Num1 - Num2;
		break;
	case '*':
		return Num1 * Num2;
		break;
	case '/':
		return Num1 / Num2;
		break;
	case '%':
		cout << "Not available yet";
		return 0;
		break;
	case '^':
		return pow(Num1, Num2);
		break;
	case '(':
		return Num1 + Num2;
		break;
	case ')':
		return Num1 + Num2;
		break;
	default:
		break;
	}
}

bool calculator_in_string::is_an_operator(char Now_char)
{
	if (Now_char == '+' || Now_char == '-' || Now_char == '*' || Now_char == '/' || Now_char == '%' || Now_char == '^' || Now_char == '(' || Now_char == ')') {
		return true;
	}
	else {
		return false;
	}
}

int calculator_in_string::compare_two_operators(char Op1, char Op2)
{
	int temp_op_w_1 = 0;
	int temp_op_w_2 = 0;

	switch (Op1)
	{
	case '+':
		temp_op_w_1 = 1;
		break;
	case '-':
		temp_op_w_1 = 1;
		break;
	case '*':
		temp_op_w_1 = 2;
		break;
	case '/':
		temp_op_w_1 = 2;
		break;
	case '%':
		temp_op_w_1 = 2;
		break;
	case '^':
		temp_op_w_1 = 3;
		break;
	case '(':
		temp_op_w_1 = 0;
		break;
	case ')':
		temp_op_w_1 = 4;
		break;
	default:
		break;
	}

	switch (Op2)
	{
	case '+':
		temp_op_w_2 = 1;
		break;
	case '-':
		temp_op_w_2 = 1;
		break;
	case '*':
		temp_op_w_2 = 2;
		break;
	case '/':
		temp_op_w_2 = 2;
		break;
	case '%':
		temp_op_w_2 = 2;
		break;
	case '^':
		temp_op_w_2 = 3;
		break;
	case '(':
		temp_op_w_2 = 0;
		break;
	case ')':
		temp_op_w_2 = 4;
		break;
	default:
		break;
	}

	if (temp_op_w_1 >= temp_op_w_2) {
		return 1;
	}
	else {
		return 0;
	}
}

void calculator_in_string::calculate()
{
	translate_to_postfix();
	calculate_postfix();
}

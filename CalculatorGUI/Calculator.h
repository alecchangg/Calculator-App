#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <iterator>

class Stack {
public:
	std::vector<std::string> stack;

	Stack() {
		stack = {};
	}

	void Push(std::string val) {
		stack.push_back(val);
	}

	std::string Peek() {
		if (!stack.empty()) {
			return stack.back();
		}
		else {
			return "";
		}
	}

	std::string Pop() {
		if (!stack.empty()) {
			std::string popped = stack.back();
			stack.pop_back();
			return popped;
		}
		else {
			return "";
		}
	}

	void PrintOut() {
		for (std::string s : stack) {
			std::cout << s;
		}
	}
};

class Calculator {
private:
	std::string expression;

	bool m_IsExpressionValid() {
		return true;
	}

	bool m_IsNumber(std::string val) {
		//not a number if val is just -, ., an empty string, or starts with a decimal.
		if (val == "-" || val == "" || val == "." || &val[0] == ".") {
			return false;
		}

		//if first char is a negative sign, remove it.
		if (val[0] == '-') {
			val.erase(0, 1);
		}

		//checks to see if the remaining chars are numerics. Only one decimal is allowed from this point onward.
		int num_decimals = 0;
		for (int i = 0; i < val.length(); i++) {
			if (val[i] == '.' && num_decimals == 0) {
				num_decimals += 1;
			}
			else if (val[i] == '.' && num_decimals != 0) {
				return false;
			}
			else if (!isdigit(val[i])) {
				return false;
			}
		}

		return true;
	}

	float m_StringToFloat(std::string str) {
		float conv;
		if (str[0] == '-') {
			str.erase(0, 1);
			conv = std::stof(str);
			conv *= -1;
		}
		else {
			conv = std::stof(str);
		}
		return conv;

	}

	std::string m_GetPostfix(std::string infix_expression) {
		//stack for infix to postfix algorithm
		Stack stack = Stack();

		//map to establish operator priority aka pemdas
		std::unordered_map<std::string, int> pemdas;
		pemdas["+"] = 1;
		pemdas["-"] = 1;
		pemdas["*"] = 2;
		pemdas["/"] = 2;
		pemdas["^"] = 3;

		//Removes spaces and puts each char into a vector
		std::stringstream ss(infix_expression);
		std::istream_iterator<std::string> begin(ss);
		std::istream_iterator<std::string> end;
		std::vector<std::string> expression_vector(begin, end);

		//Infix to postfix algorithm
		std::string postfix_expression = "";
		for (std::string s : expression_vector) {
			if (this->m_IsNumber(s)) {
				postfix_expression += s + " ";
			}
			else if (s == "(") {
				stack.Push(s);
			}
			else if (pemdas.find(s) != pemdas.end()) {
				while (pemdas[stack.Peek()] >= pemdas[s]) {
					postfix_expression += stack.Pop() + " ";
				}
				stack.Push(s);
			}
			else if (s == ")") {
				while (stack.Peek() != "(") {
					postfix_expression += stack.Pop() + " ";
				}
				stack.Pop();
			}
		}
		while (stack.Peek() != "") {
			postfix_expression += stack.Pop() + " ";
		}
		return postfix_expression;
	}
public:
	Calculator() {
		expression = "";
	}

	//returns the inputted expression
	std::string GetExpression() {
		return expression;
	}

	//sets the inputted expression
	void SetExpression(std::string input_expression) {
		expression = input_expression;
	}

	//calculates the inputted expression and returns the result
	std::string Calculate() {
		//checks to see if the set expression is a valid math expression
		if (!m_IsExpressionValid()) {
			return "Invalid Expression";
		}

		Stack stack = Stack();
		float calc;

		//map to establish operator priority aka pemdas
		std::unordered_map<std::string, int> pemdas;
		pemdas["+"] = 1;
		pemdas["-"] = 2;
		pemdas["*"] = 3;
		pemdas["/"] = 4;
		pemdas["^"] = 5;

		std::string postfix = this->m_GetPostfix(expression);

		//Removes spaces and puts each char into a vector
		std::stringstream ss(postfix);
		std::istream_iterator<std::string> begin(ss);
		std::istream_iterator<std::string> end;
		std::vector<std::string> postfix_vector(begin, end);

		for (std::string s : postfix_vector) {
			if (this->m_IsNumber(s)) {
				stack.Push(s);
			}
			else if (pemdas.find(s) != pemdas.end()) {
				float num1 = this->m_StringToFloat(stack.Pop());
				float num2 = this->m_StringToFloat(stack.Pop());
				if (pemdas[s] == 4) {
					calc = num2 / num1;
				}
				else if (pemdas[s] == 3) {
					calc = num2 * num1;
				}
				else if (pemdas[s] == 2) {
					calc = num2 - num1;
				}
				else if (pemdas[s] == 1) {
					calc = num2 + num1;
				}
				stack.Push(std::to_string(calc));
			}
		}

		return stack.Pop();
	}

};
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

		bool m_IsNumber(std::string val) {
			//not a number if val is just -, ., an empty string, or starts with a decimal.
			if (val == "-" || val == "" || val == "." || &val[0] == ".") {
				return false;
			}
			
			//if first char is a negative sign, remove it.
			if (&val[0] == "-") {
				val.erase(0, 1);
			}

			//checks to see if the remaining chars are numerics. Only one decimal is allowed from this point onward.
			int num_decimals = 0;
			for (int i = 0; i < val.length(); i++) {
				if (&val[i] == "." && num_decimals == 0) {
					num_decimals += 1;
				}
				else if (&val[i] == "." && num_decimals != 0) {
					return false;
				}
				else if (!isdigit(val[i])) {
					return false;
				}
			}

			return true;
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
			std::vector<std::string> expression_without_spaces(begin, end);

			//Infix to postfix algorithm
			std::string postfix_expression = "";
			for (std::string s : expression_without_spaces) {
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

		std::string GetExpression() {
			return expression;
		}

		void SetExpression(std::string input_expression) {
			expression = input_expression;
		}

};


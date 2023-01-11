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

		/*bool m_IsNumber(std::string val) {
			
		}*/

		std::string m_GetPostfix(std::string infix_expression) {
			Stack stack = Stack();
			std::string postfix = "";
			std::unordered_map<std::string, int> pemdas;
			pemdas["+"] = 3;
			pemdas["-"] = 3;
			pemdas["*"] = 2;
			pemdas["/"] = 2;
			pemdas["^"] = 1;
			
			//Removes spaces and puts each char into a vector
			std::stringstream ss(infix_expression);
			std::istream_iterator<std::string> begin(ss);
			std::istream_iterator<std::string> end;
			std::vector<std::string> expression_without_spaces(begin, end);

			

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


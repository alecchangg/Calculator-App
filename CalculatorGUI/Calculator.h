#pragma once
#include <string>
#include <vector>
#include <iostream>

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
};


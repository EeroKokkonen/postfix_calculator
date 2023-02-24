#pragma once
#include <iostream>
#include <stack>
#include <ctype.h>


// Singleton
class Calculator
{
public:
	// Makes copying not possible
	Calculator(const Calculator&) = delete;

	// To get instance of this class
	static Calculator& Get();

	// Public calculate function, makes calling this function possible without getting instance
	static int calculate(std::string& calculation);
	
private:
	// Makes it not possible to create new object
	Calculator() {}

	// Internal calculate function
	int iCalculate(std::string& calculation);

	// Calculates the value
	void doCalculation(char _operator);

	// Handles given command
	void handleCommand(char command);

	// Clears stack
	void clearStack();

	// Gets total sum of numbers in stack
	int getSum();

	// Check if the character is operator
	bool isOperator(char character);

	// Check if the character is command
	bool isCommand(char character);

	// Stack that is storing nubers that are needed for calculation
	std::stack<int> calculationStack;

	// Implemented operators for this calculator
	const char operators[6] = { '+', '-', '*', '/', '%', 'v'};

	/*
		Implemented commands for this calculator
	    x = swap, s = sum, a = average
	*/
	const char commands[3] = { 'x', 's', 'a' };
};


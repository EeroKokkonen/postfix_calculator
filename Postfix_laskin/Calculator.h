#pragma once
#include <iostream>
#include <stack>
#include <ctype.h>


// Singleton
class Calculator
{
public:
	Calculator(const Calculator&) = delete;

	// To get instance of this class
	static Calculator& Get();

	static float calculate(std::string& calculation);
	
private:
	Calculator() {}

	float iCalculate(std::string& calculation);

	void saveCalculationToStack(std::string& calculation);

	void doCalculation(char _operator);

	void handleCommand(char command);

	bool isOperator(char character);

	bool isCommand(char character);

	std::stack<float> calculationStack;

	const char operators[4] = { '+', '-', '*', '/' };

	const char commands[2] = { 'x', 's'};

	int answer;
};


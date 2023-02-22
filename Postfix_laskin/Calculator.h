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

	bool isOperator(char character);

	std::stack<float> calculationStack;

	const char operators[4] = { '+', '-', '*', '/'};

	int answer;
};


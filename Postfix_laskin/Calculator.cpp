#include "Calculator.h"
namespace utils
{
	std::string getString(int argc, char** argv)
	{
		std::string userInput = "";
		for (int i = 1; i < argc; i++)
		{
			userInput += argv[i];
		}
		return userInput;
	}

	int charToFloat(char character)
	{
		return float(character) - 48;
	}
}

Calculator& Calculator::Get()
{
	static Calculator instance;
	return instance;
}

float Calculator::calculate(std::string& calculation)
{
	return Get().iCalculate(calculation);
}

float Calculator::iCalculate(std::string& calculation)
{
	for (int i = 0; i < calculation.length(); i++)
	{
		if (isCommand(calculation[i]))
		{
			handleCommand(calculation[i]);
		}

		if (isdigit(calculation[i]))
		{
			calculationStack.push(utils::charToFloat(calculation[i]));
			continue;
		}

		if (isOperator(calculation[i]))
		{
			doCalculation(calculation[i]);
		}
	}
	return calculationStack.top();
}

void Calculator::saveCalculationToStack(std::string& calculation)
{
	for (int i = 0; i < calculation.length(); i++)
	{
		calculationStack.push(calculation[i]);
	}
}

void Calculator::doCalculation(char _operator)
{
	float numb1 = calculationStack.top();
	calculationStack.pop();
	float numb2 = calculationStack.top();
	calculationStack.pop();

	switch (_operator)
	{
		case '+':
			calculationStack.push(numb2 + numb1);
			break;
		case '-':
			calculationStack.push(numb2 - numb1);
			break;
		case '*':
			calculationStack.push(numb2 * numb1);
			break;
		case '/':
			calculationStack.push(numb2 / numb1);
			break;
		case '^':
			calculationStack.push(pow(numb2, numb1));
	}
}

void Calculator::handleCommand(char command)
{
	std::stack<float> temoraryStack;

	switch (command)
	{
	case 'x':	// change positions of two numbers in stack
		temoraryStack.push(calculationStack.top());
		calculationStack.pop();
		temoraryStack.push(calculationStack.top());
		calculationStack.swap(temoraryStack);
		break;
	case 's':
	{
		float sum = 0;
		int stackSize = calculationStack.size();

		for (int i = 0; i < stackSize; i++)
		{
			sum += calculationStack.top();
			calculationStack.pop();
		}

		calculationStack.push(sum);
		break;
	}
	default:
		std::cout << "Unknown command \"" << command << "\"!" << std::endl;
		break;
	}
}

bool Calculator::isOperator(char character)
{
	for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++)
	{
		if (character == operators[i])
			return true;
	}
	return false;
}

bool Calculator::isCommand(char character)
{
	for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
	{
		if (character == commands[i])
			return true;
	}
	return false;
}




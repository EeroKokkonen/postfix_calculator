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

	int charToint(char character)
	{
		return int(character) - 48;
	}
}

Calculator& Calculator::Get()
{
	static Calculator instance;
	return instance;
}

int Calculator::calculate(std::string& calculation)
{
	return Get().iCalculate(calculation);
}

int Calculator::iCalculate(std::string& calculation)
{
	for (int i = 0; i < calculation.length(); i++)
	{
		if (isCommand(calculation[i]))
		{
			handleCommand(calculation[i]);
		}

		if (isdigit(calculation[i]))
		{
			calculationStack.push(utils::charToint(calculation[i]));
			continue;
		}

		if (isOperator(calculation[i]))
		{
			doCalculation(calculation[i]);
		}
	}
	return calculationStack.top();
}

void Calculator::doCalculation(char _operator)
{
	int numb1 = calculationStack.top();
	calculationStack.pop();
	int numb2 = calculationStack.top();
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
			calculationStack.push((int)pow(numb2, numb1));
			break;
		case '%':
			calculationStack.push(numb2 % numb1);
			break;
		default:
			std::cout << "Unknown operator \"" << _operator << "\"!" << std::endl;
			break;
	}
}

void Calculator::handleCommand(char command)
{
	switch (command)
	{
	case 'x':	// change positions of two numbers in stack
	{
		std::stack<int> temoraryStack;

		temoraryStack.push(calculationStack.top());

		calculationStack.pop();

		temoraryStack.push(calculationStack.top());

		calculationStack.swap(temoraryStack);

		break;
	}
	case 's': // calculates sum of stack numbers, deletes those numbers and add sum top of stack
	{
		int sum = getSum();

		clearStack();

		calculationStack.push(sum);

		break;
	}
	case 'a': // calculates average of stack numbers, deletes those numbers and add average top of stack
	{
		int average = getSum() / (int)calculationStack.size();

		clearStack();

		calculationStack.push(average);

		break;
	}
	case 'v':
	{
		int squareRoot = (int) sqrt(calculationStack.top());
		clearStack();
		calculationStack.push(squareRoot);
	}
	default:
		std::cout << "Unknown command \"" << command << "\"!" << std::endl;
		break;
	}
}

void Calculator::clearStack()
{
	int stackSize = (int) calculationStack.size();

	for (int i = 0; i < stackSize; i++)
	{
		calculationStack.pop();
	}
}

int Calculator::getSum()
{
	int stackSize = (int) calculationStack.size();

	std::stack<int> temoraryStack = calculationStack;

	int sum = 0;

	for (int i = 0; i < stackSize; i++)
	{
		sum += temoraryStack.top();
		temoraryStack.pop();
	}
	return sum;
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
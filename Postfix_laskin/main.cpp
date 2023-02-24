#include "Calculator.h"
#include <string>

std::string getString(int argc, char** argv);
bool isPromptOn(char** argv);

int main(int argc, char** argv)
{
	std::string calculation;
	if (argc == 1)
	{
		std::cout << "No calculation or promp command!" << std::endl;
		return 1;
	}
	if (isPromptOn(argv))
	{
		std::cout << "Type Postfix type calculation: \n";
		std::getline(std::cin, calculation);
	}
	else
		calculation = getString(argc, argv);

	std::cout << Calculator::calculate(calculation) << std::endl;

	return 0;
}

bool isPromptOn(char** argv)
{
	if ((std::string)argv[1] == "-p")
		return true;

	return false;
}

std::string getString(int argc, char** argv)
{
	std::string userInput = "";
	for (int i = 1; i < argc; i++)
	{
		userInput += argv[i];
	}
	return userInput;
}
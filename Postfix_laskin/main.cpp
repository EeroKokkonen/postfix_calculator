#include "Calculator.h"

int main(int argc, char** argv)
{
	//std::string calculation = utils::getString(argc, argv);

	Calculator& testi = Calculator::Get();

	std::string calculation = "1 2 3 s";

	std::cout << Calculator::calculate(calculation) << std::endl;
}
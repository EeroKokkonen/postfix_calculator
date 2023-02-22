#include "Calculator.h"



int main(int argc, char** argv)
{
	//std::string calculation = utils::getString(argc, argv);

	Calculator& testi = Calculator::Get();
	std::string calculation = "27-5*";
	std::cout << Calculator::calculate(calculation) << std::endl;
}
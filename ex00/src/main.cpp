#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "--- TESTE 1: Burocrata nascendo com nota errada ---" << std::endl;
	try 
	{
		Bureaucrat b1("Zaphod", 151); 
		std::cout << b1 << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "" << e.what() << std::endl;
	}

	std::cout << "\n--- TESTE 2: Incrementando além do limite ---" << std::endl;
	try 
	{
		Bureaucrat b2("Marvin", 2);
		std::cout << b2 << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		b2.incrementGrade();
	} 
	catch (const std::exception& e) 
	{
		std::cerr << "" << e.what() << std::endl;
	}

	return 0;
}
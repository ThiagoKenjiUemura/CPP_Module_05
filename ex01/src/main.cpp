#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=========================================" << std::endl;
	std::cout << "TESTE 1: Assinatura bem-sucedida" << std::endl;
	std::cout << "=========================================" << std::endl;
	try
	{
		Bureaucrat hermes("Hermes", 10);
		Form formA("Formulário de Férias", 50, 50);

		std::cout << hermes << std::endl;
		std::cout << formA << std::endl;

		hermes.signForm(formA);

		std::cout << formA << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Erro inesperado: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "TESTE 2: Burocrata com nota muito baixa" << std::endl;
	std::cout << "=========================================" << std::endl;
	try
	{
		Bureaucrat estagiario("Estagiário", 150);
		Form formB("Formulário Ultra Secreto", 1, 1);

		std::cout << estagiario << std::endl;
		std::cout << formB << std::endl;

		estagiario.signForm(formB);
	}
	catch (std::exception& e)
	{
		std::cerr << "Erro inesperado: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "TESTE 3: Formulário com nota de assinatura alta demais (< 1)" << std::endl;
	std::cout << "=========================================" << std::endl;
	try
	{
		Form formC("Formulário Impossível", 0, 50);
		
		std::cout << "Isto não deve ser impresso!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exceção capturada com sucesso: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "TESTE 4: Formulário com nota de execução baixa demais (> 150)" << std::endl;
	std::cout << "=========================================" << std::endl;
	try
	{
		Form formD("Formulário Inútil", 50, 151);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exceção capturada com sucesso: " << e.what() << std::endl;
	}

	return 0;
}

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "\n=========================================" << std::endl;
    std::cout << "--- TESTE 1: A Burocracia Perfeita ---" << std::endl;
    std::cout << "=========================================\n" << std::endl;
    try 
    {
        Bureaucrat boss("Chefe", 1);
        ShrubberyCreationForm form1("Jardim");
        RobotomyRequestForm form2("Bender");
        PresidentialPardonForm form3("Arthur Dent");

        std::cout << "\n[Assinando os formulários]" << std::endl;
        boss.signForm(form1);
        boss.signForm(form2);
        boss.signForm(form3);

        std::cout << "\n[Executando os formulários]" << std::endl;
        boss.executeForm(form1);
        boss.executeForm(form2);
        boss.executeForm(form3);
    }
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=========================================" << std::endl;
    std::cout << "--- TESTE 2: Nota boa para assinar, ruim para executar ---" << std::endl;
    std::cout << "=========================================\n" << std::endl;
    try 
    {
        Bureaucrat estagiario("Estagiario", 140); 
        ShrubberyCreationForm form("Praca");

        estagiario.signForm(form);
        std::cout << "Tentando executar..." << std::endl;
        estagiario.executeForm(form);
    }
    catch (std::exception &e) 
    {
        std::cerr << "Erro fatal: " << e.what() << std::endl;
    }

    std::cout << "\n=========================================" << std::endl;
    std::cout << "--- TESTE 3: Formulário não assinado ---" << std::endl;
    std::cout << "=========================================\n" << std::endl;
    try 
    {
        Bureaucrat diretor("Diretor", 5);
        PresidentialPardonForm form("Ford Prefect");

        std::cout << "Tentando executar direto..." << std::endl;
        diretor.executeForm(form);
    }
    catch (std::exception &e) 
    {
        std::cerr << "Erro fatal: " << e.what() << std::endl;
    }

    std::cout << "\nFim dos testes." << std::endl;
    return 0;
}

#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
    std::cout << "--- EXERCÍCIO 03: O ESTAGIÁRIO (INTERN) ---" << std::endl;
    std::cout << "=========================================\n" << std::endl;

    Intern someRandomIntern;
    Bureaucrat boss("Chefe Supremo", 1);

    std::cout << "\n[1] Estagiário criando um RobotomyRequestForm:" << std::endl;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf != NULL)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n[2] Estagiário criando um ShrubberyCreationForm:" << std::endl;
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Jardim_do_Estagiario");
    if (scf != NULL)
    {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf; 
    }

    std::cout << "\n[3] Estagiário criando um PresidentialPardonForm:" << std::endl;
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (ppf != NULL)
    {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf; 
    }

    std::cout << "\n[4] Estagiário tentando criar um Formulário Inexistente:" << std::endl;
    AForm* errorForm = someRandomIntern.makeForm("formulario do cafe", "Copa");
    if (errorForm != NULL)
    {
        boss.signForm(*errorForm);
        boss.executeForm(*errorForm);
        delete errorForm;
    }

    std::cout << "\nFim dos testes do CPP05." << std::endl;
    return 0;
}

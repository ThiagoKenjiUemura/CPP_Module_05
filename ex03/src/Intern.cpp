#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Creator Called." << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern Copy Creator Called." << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern Copy Assignment Operator Called." << std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called." << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int index = -1;

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			index = i;
			break;
		}
	}

	switch (index)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		
		default:
			std::cout << "Intern could not create form: " << formName << " does not exist." << std::endl;
			return NULL;
	}
}
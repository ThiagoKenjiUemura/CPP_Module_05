#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) , _target("default_target")
{
	std::cout << "RobotomuRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Parametrized Constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm Copy Assignment operator called." << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called." << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* VRRRRRRRR... BZZZZZZ... RATATATATA! *" << std::endl;
    std::cout << "(Barulhos assustadores de furadeira)" << std::endl;

	if(std::rand() % 2 == 0)
	{
		std::cout << "Sucesso! " << this->_target << " foi robotizado com perfeição." << std::endl;
	}
	else
	{
		std::cout << "Falha! A robotomia de " << this->_target << " deu terrivelmente errado." << std::endl;
	}
}
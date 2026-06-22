#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("No Name Bureaucrat"), grade(150)
{
	std::cout << "Default contructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const ::std string& targetName, int targetGrade) : name(targetName) , grade(targetGrade)
{
	std::cout << "Bureaucrat Parametrized constructor called"<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat Copy contructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor callded" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}
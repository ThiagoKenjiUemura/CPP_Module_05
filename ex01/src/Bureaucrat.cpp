#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), __grade(other._grade)
{
	std::cout << "Bureaucrat Copy constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& targetName, int targetGrade) : _name(targetName), _grade(targetGrade)
{
	std::cout << "Bureaucrat Parametrized constructor called." << std::endl;
	if(_grade < 1){
		throw Bureaucrat::GradeTooHighException();
	} else if(_grade > 150){
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Copy assignment operator called." << sd::endl;
	if(this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat contructor called." << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if(this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150)
{
	std::cout << "Default contructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& targetName, int targetGrade) : _name(targetName) , _grade(targetGrade)
{
	std::cout << "Bureaucrat Parametrized constructor called"<< std::endl;
	if (_grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
	else if (_grade > 150){
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat Copy contructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor callded" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Bureaucrat's grade is too high! (Max: 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Bureaucrat's grade is too low! (Min: 150)";
}

void Bureaucrat::incrementGrade()
{
	if(this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if(this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()  << ".";
	return os;
}
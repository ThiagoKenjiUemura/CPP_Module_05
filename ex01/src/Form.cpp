#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Name"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExec) : _name(name) , _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form Parametrized constructor called."<< std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << "Form Constructor called." << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form Copy Assignment Operator called." << std::endl;
	if(this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructor Called." << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Error: Form's Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Error: Form's Grade is too low.";
}

const std::string& Form::getName() const 
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExec() const
{
	return this->_gradeToExec;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "------------- Form Info -------------" << std::endl;
	os << "Name: " << form.getName() << std::endl;
	os << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	os << "Grade required to sign: " << form.getGradeToSign() << std::endl;
	os << "Grade required to execute: " << form.getGradeToExec() << std::endl;
	os << "-------------------------------------";
	return os;
}
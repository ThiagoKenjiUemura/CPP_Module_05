#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Name"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExec) : _name(name) , _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "AForm Parametrized constructor called."<< std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << "AForm Constructor called." << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm Copy Assignment Operator called." << std::endl;
	if(this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called." << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Error: Form's Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Error: Form's Grade is too low.";
}

const std::string& AForm::getName() const 
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExec() const
{
	return this->_gradeToExec;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Error: Form cannot be executed because it is not signed.";
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	this->executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "------------- Form Info -------------" << std::endl;
	os << "Name: " << form.getName() << std::endl;
	os << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	os << "Grade required to sign: " << form.getGradeToSign() << std::endl;
	os << "Grade required to execute: " << form.getGradeToExec() << std::endl;
	os << "-------------------------------------";
	return os;
}
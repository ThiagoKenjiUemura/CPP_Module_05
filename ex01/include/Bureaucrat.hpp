#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string& targetName, int targetGrade);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GetTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GetTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		}
};

#endif
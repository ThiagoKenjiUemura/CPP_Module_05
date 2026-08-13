# 🏢 CPP Module 05 - 42 School

> *"Bureaucracy, exceptions, and a lot of object-oriented programming in C++98."*

This repository contains my solution for **CPP Module 05** of [42 School]. The main goal of this module is to introduce crucial security and architecture concepts in C++, specifically error handling (Exceptions) and diving deeper into Polymorphism and Abstract Classes.

## 🧠 Concepts Covered

Throughout this module, we step away from traditional C error codes (`return -1;`) and start using the native C++ exception handling system.

*   **Try / Catch / Throw:** Safe flow management when errors occur.
*   **Custom Exceptions:** Creating error classes inheriting from `std::exception`.
*   **Abstract Classes:** Using pure virtual functions (`= 0`) to create interfaces.
*   **Polymorphism in Action:** Executing child class methods through parent class pointers/references.
*   **Factory Pattern:** Dynamic object creation at runtime.

---

## 📂 Exercises Structure

### Exercise 00: *Mommy, when I grow up I want to be a bureaucrat!*
Introduction to the `Bureaucrat` class. Each bureaucrat has a name (constant) and a grade ranging from 1 (highest) to 150 (lowest).
*   **Focus:** Implementing `try/catch` blocks and throwing exceptions (`GradeTooHighException` and `GradeTooLowException`) if there's an attempt to instantiate or promote a bureaucrat with invalid grades.

### Exercise 01: *Form up, maggots!*
Creation of the `Form` class. A form requires specific minimum grades to be both signed and executed.
*   **Focus:** Safe interaction between objects. The Bureaucrat tries to sign the form; if their grade is too low, the form throws an exception detailing the reason for the failure.

### Exercise 02: *No, you need form 28B, not 28C...*
The architectural core of the module. The `Form` class becomes an Abstract Class (`AForm`), serving as a base for 3 concrete forms:
1.  **ShrubberyCreationForm:** Creates a file and draws ASCII trees inside it.
2.  **RobotomyRequestForm:** Makes drilling noises and has a 50% chance of successfully "robotomizing" the target.
3.  **PresidentialPardonForm:** Prints that the target has been pardoned by Zaphod Beeblebrox.
*   **Focus:** Polymorphism. The bureaucrat receives a generic `AForm`, and C++ determines at runtime which child class is the correct one to execute the action, enforcing the grade and signature rules.

### Exercise 03: *At least this beats coffee-making*
Introduction to the `Intern` class. The intern has no name and no grade; their only job is to manufacture forms upon a bureaucrat's request.
*   **Focus:** Implementation of the **Factory Pattern**. The intern takes strings (the name of the form and the target) and uses an array of strings paired with a `switch-case` (without using *if/else if*) to allocate and return the correct form using the `new` keyword.

---

## 🛠️ How to Compile and Test

The project was written in compliance with the C++98 standard and compiles strictly with the `-Wall -Wextra -Werror` flags.

1. Clone the repository:
```bash
git clone [https://github.com/YOUR_USERNAME/cpp05.git](https://github.com/YOUR_USERNAME/cpp05.git)
cd cpp05
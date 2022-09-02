#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat temp("Norm1", 3);
		std::cout << temp;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat temp("Error1", 0);
		std::cout << temp;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat temp("Error2", 151);
		std::cout << temp;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat temp("Norm2", 2);
		temp.increment();
		std::cout << temp;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat temp("Error3", 1);
		temp.increment();
		std::cout << temp;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat temp("Norm3", 149);
		temp.decrement();
		std::cout << temp;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat temp("Error4", 150);
		temp.decrement();
		std::cout << temp;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
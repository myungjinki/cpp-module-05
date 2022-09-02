#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : Form("Robotomy Request Form", target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	Form::operator=(other);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << "brzz... brzz... brzz... brzz... " << std::endl;
	if (rand() % 2 == 0)
		throw RobotomyRequestForm::FailedToRobotomize();
	std::cout << "<" << getTarget() << "> has been robotomized successfully" << std::endl;
}

const char *RobotomyRequestForm::FailedToRobotomize::what() const _NOEXCEPT
{
	return "Error: RobotomyRequestForm: Failed To Robotomize!";
}
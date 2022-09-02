#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern()
{

}

Intern &Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

static Form*	createPresidentialPardonForm(std::string & target) { return (new PresidentialPardonForm(target)); }
static Form*	createRobotomyRequestForm(std::string & target) { return (new RobotomyRequestForm(target)); }
static Form*	createShrubberyCreationForm(std::string & target) { return (new ShrubberyCreationForm(target)); }

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = 
    {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
	Form* (*functions[3])(std::string &tt) = 
	{
		createPresidentialPardonForm,
		createRobotomyRequestForm,
		createShrubberyCreationForm
	};
	for (int i = 0;i < 3;i++)
		if (name == names[i])
			return functions[i](target);
	throw Intern::FormNotFoundException();
	return NULL;
}

const char* Intern::FormNotFoundException::what() const _NOEXCEPT
{
	return "Error: Intern: Form Not Found!";
}

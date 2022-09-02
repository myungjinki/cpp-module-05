#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : Form("Presidential Pardon Form", target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	Form::operator=(other);
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << "<" << getTarget() << "> has been pardoned by Zafod Beeblebrox" << std::endl;
}

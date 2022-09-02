#ifndef ShrubberyCreationForm_hpp
#define ShrubberyCreationForm_hpp

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string const &);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
	virtual void execute(Bureaucrat const &) const;

	class fileOpenFailed : public std::exception
	{
	public:
		 virtual const char* what() const _NOEXCEPT;
	};

};

#endif
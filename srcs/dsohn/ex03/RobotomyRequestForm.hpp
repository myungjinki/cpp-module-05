#ifndef RobotomyRequestForm_hpp
#define RobotomyRequestForm_hpp

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string const &);
	RobotomyRequestForm(const RobotomyRequestForm&);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm&);
	virtual void execute(Bureaucrat const &) const;

	class FailedToRobotomize : public std::exception
	{
	public:
		 virtual const char* what() const _NOEXCEPT;
	};
};

#endif

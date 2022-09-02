#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : Form("Shrubbery Creation Form", target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	Form::operator=(other);
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string tree = "";
	tree.append("                                              .\n");
	tree.append("                                   .         ;\n");
	tree.append("      .              .              ;%     ;;\n");
	tree.append("       ,           ,                :;%  %;\n");
	tree.append("         :         ;                   :;%;'     .,\n");
	tree.append(",.        %;     %;            ;        %;'    ,;\n");
	tree.append("  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n");
	tree.append("   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n");
	tree.append("    ;%;      %;        ;%;        % ;%;  ,%;'\n");
	tree.append("     `%;.     ;%;     %;'         `;%%;.%;'\n");
	tree.append("      `:;%.    ;%%. %@;        %; ;@%;%'\n");
	tree.append("         `:%;.  :;bd%;          %;@%;'\n");
	tree.append("           `@%:.  :;%.         ;@@%;'\n");
	tree.append("             `@%.  `;@%.      ;@@%;\n");
	tree.append("               `@%%. `@%%    ;@@%;\n");
	tree.append("                 ;@%. :@%%  %@@%;\n");
	tree.append("                   %@bd%%%bd%%:;\n");
	tree.append("                     #@%%%%%:;;\n");
	tree.append("                     %@@%%%::;\n");
	tree.append("                     %@@@%(o);  . '\n");
	tree.append("                     %@@@o%;:(.,'\n");
	tree.append("                 `.. %@@@o%::;\n");
	tree.append("                    `)@@@o%::;\n");
	tree.append("                     %@@(o)::;\n");
	tree.append("                    .%@@@@%::;\n");
	tree.append("                    ;%@@@@%::;.\n");
	tree.append("                   ;%@@@@%%:;;;.\n");
	tree.append("               ...;%@@@@@%%:;;;;,..\n");

	Form::execute(executor);
	std::ofstream out;
	out.open((getTarget() + "_shrubbery").c_str(), std::ios::out | std::ios::trunc | std::ios::binary);
	if (!out.is_open())
		throw ShrubberyCreationForm::fileOpenFailed();
	out << tree;
	out.close();
}

const char *ShrubberyCreationForm::fileOpenFailed::what() const _NOEXCEPT
{
	return "Error: ShrubberyCreationForm: Opening File Failed!";
}
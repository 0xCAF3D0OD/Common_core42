//
// Created by Kevin Di nocera on 11/9/22.
//

#include "AForm.hpp"

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("the number is to low\n");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("the number is to high\n");
}

const char *AForm::NameNotCharException::what() const throw()
{
	return ("the name is not a array\n");
}

const char *AForm::NotSigned::what() const throw()
{
	return ("Form isn't signed\n");

}
AForm::AForm(void)
: _name(""),
_executeGrade(0),
_signedGrade(0),
_isSigned(false)
{
	std::cout << "default constructor is called" << std::endl;
}

AForm::AForm(std::string const &name, int const executeGrade, int const signedGrade)
: _name(name),
_executeGrade(executeGrade),
_signedGrade(signedGrade),
_isSigned(false)
{
	if (_executeGrade < 1 || _signedGrade < 1)
		throw GradeTooHighException();
	if (_executeGrade > 150 || _signedGrade > 150)
		throw GradeTooLowException();
	for (size_t i = 0; i < _name.length(); i++)
	{
		if (!isalpha(_name[i]))
			throw Bureaucrat::NameNotCharException();
	}
	std::cout << "initialiser constructor is called" << std::endl;
}

AForm::AForm(AForm const &src)
:	_name(src._name),
_executeGrade(src._executeGrade),
_signedGrade(src._signedGrade),
_isSigned(src._isSigned)
{
	std::cout << "copy constructor is called" << std::endl << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
	_isSigned = rhs._isSigned;
	std::cout << "isSigned is the only one to be initialised with operator '=' the others are const"
	<< std::endl;
	return (*this);
}

bool	AForm::beSigned(Bureaucrat *Bernard)
{
	if (Bernard->getGrade() <= getSignedGrade())
	{
		_isSigned = true;
		return (true);
	}

	return (false);
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (this->_isSigned)
	{
		if (executor.getGrade() > this->_executeGrade)
		{
			std::cout << executor.getName() << BOLD_RED << " can't execute "
			<< this->_name << RESET << std::endl;
			throw AForm::GradeTooLowException();
		}
		std::cout << executor.getName() << BOLD_G << " has executed "
		<< this->_name << RESET << std::endl;
		this->executeAction();
	}
	else
	{
		std::cout << BOLD_RED << executor.getName() << " can't execute " << this->_name << RESET << std::endl;
		throw AForm::NotSigned();
	}
}

std::string	AForm::getName() const
{
	return (this->_name);
}

int	AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

int	AForm::getSignedGrade() const
{
	return (_signedGrade);
}

bool	AForm::getSigned() const
{
	return (_isSigned);
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor is called" << std::endl;
}
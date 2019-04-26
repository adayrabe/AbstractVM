//
// Created by Dayrabekov Artem on 2019-04-25.
//

#include "OperandExceptions.hpp"

const char *OperandExceptions::ValueOverflowException::what() const throw()
{
    return "Overflow of a value";
}

const char *OperandExceptions::ValueUnderflowException::what() const throw()
{
	return "Underflow of a value";
}

const char *OperandExceptions::ZeroDivisionException::what() const throw()
{
	return "Division by zero";
}

const char *OperandExceptions::ZeroModuloException::what() const throw()
{
	return "Modulo by zero";
}

const char *OperandExceptions::FloatingPointModuloFromException::what() const throw()
{
	return "Trying to get modulo from a floating point";
}

const char *OperandExceptions::FloatingPointModuloOfException::what() const throw()
{
	return "Trying to get modulo of a floating point";
}

const char *OperandExceptions::WrongCharacterException::what() const throw()
{
	return "Wrong character in number";
}
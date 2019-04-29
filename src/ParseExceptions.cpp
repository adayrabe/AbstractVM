//
// Created by Dayrabekov Artem on 2019-04-29.
//

#include <ParseExceptions.hpp>

#include "ParseExceptions.hpp"

const char *ParseExceptions::WrongCommandException::what() const throw()
{
	return "Wrong command";
}

const char *ParseExceptions::WrongSymbolsAtTheEndOfLineException::what() const throw()
{
	return "Wrong symbols at the end of line";
}

const char *ParseExceptions::NoOpenBracketException::what() const throw()
{
	return "No open bracket to write the number in";
}

const char *ParseExceptions::WrongOperandExcetion::what() const throw()
{
	return "Wrong operand";
}

const char *ParseExceptions::NoClosingBracketException::what() const throw()
{
	return "No closing bracket for number";
}
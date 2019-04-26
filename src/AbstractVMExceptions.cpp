//
// Created by Dayrabekov Artem on 2019-04-26.
//

#include <AbstractVMExceptions.hpp>

#include "AbstractVMExceptions.hpp"


const char *AbstractVMExceptions::PopOnEmptyStackException::what() const throw()
{
	return "Pop on empty stack";
}

const char *AbstractVMExceptions::AssertException::what() const throw()
{
	return "Assertion is wrong";
}

const char *AbstractVMExceptions::NotEnoughArgumentsException::what() const throw()
{
	return "There is not enough arguments to perform the operation";
}


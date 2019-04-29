//
// Created by Dayrabekov Artem on 2019-04-29.
//

#include "ParseExceptions.hpp"

ParseExceptions::ParseExceptions()
{}

ParseExceptions::ParseExceptions(ParseExceptions const &other)
{
	*this = other;
}

//TODO: add correct variable assignments
ParseExceptions &ParseExceptions::operator=(ParseExceptions const &other)
{
	static_cast<void>(other);
	return *this;
}

ParseExceptions::~ParseExceptions()
{}

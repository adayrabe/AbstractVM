//
// Created by Dayrabekov Artem on 2019-04-29.
//

#ifndef ABSTRACTVM_PARSEEXCEPTIONS_HPP
#define ABSTRACTVM_PARSEEXCEPTIONS_HPP


#include <iostream>

class ParseExceptions
{
	public:
		ParseExceptions();

		ParseExceptions(ParseExceptions const &other);

		ParseExceptions &operator=(ParseExceptions const &other);

		virtual ~ParseExceptions();
};


#endif //ABSTRACTVM_PARSEEXCEPTIONS_HPP

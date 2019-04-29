//
// Created by Dayrabekov Artem on 2019-04-29.
//

#ifndef ABSTRACTVM_PARSEEXCEPTIONS_HPP
#define ABSTRACTVM_PARSEEXCEPTIONS_HPP


#include <iostream>

class ParseExceptions
{
	public:
		class WrongCommandException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class WrongSymbolsAtTheEndOfLineException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NoOpenBracketException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class WrongOperandExcetion : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NoClosingBracketException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};


#endif //ABSTRACTVM_PARSEEXCEPTIONS_HPP

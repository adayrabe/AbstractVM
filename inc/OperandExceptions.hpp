//
// Created by Dayrabekov Artem on 2019-04-25.
//

#ifndef ABSTRACTVM_AOPERANDEXCEPTIONS_HPP
#define ABSTRACTVM_AOPERANDEXCEPTIONS_HPP


#include <iostream>

class OperandExceptions
{
	public:
		class ValueOverflowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class ValueUnderflowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class ZeroDivisionException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class ZeroModuloException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FloatingPointModuloFromException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FloatingPointModuloOfException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class WrongCharacterException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


#endif //ABSTRACTVM_AOPERANDEXCEPTIONS_HPP

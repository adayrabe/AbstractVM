//
// Created by Dayrabekov Artem on 2019-04-26.
//

#ifndef ABSTRACTVM_ABSTRACTVMEXCEPTIONS_HPP
#define ABSTRACTVM_ABSTRACTVMEXCEPTIONS_HPP


#include <iostream>

class AbstractVMExceptions
{
	public:
		class PopOnEmptyStackException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class AssertException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NotEnoughArgumentsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


#endif //ABSTRACTVM_ABSTRACTVMEXCEPTIONS_HPP

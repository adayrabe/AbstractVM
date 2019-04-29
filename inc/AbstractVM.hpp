//
// Created by Dayrabekov Artem on 2019-04-26.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP


#include <iostream>
#include <stack>
#include "IOperand.hpp"
class AbstractVM
{
	private:
		std::stack<IOperand const *>_stack;
		bool _exited;
	public:
		AbstractVM();

		AbstractVM(AbstractVM const &other);

		AbstractVM &operator=(AbstractVM other);

		~AbstractVM();
		void push(IOperand const *operand);
		void pop();
		std::string dump()const;
		void assertV(IOperand const *operand);
		void getArg(IOperand const **a);

		void add();
		void sub();
		void mul();
		void div();
		void mod();
		std::string print()const;
		void exit();
		void tryToTerminate();
};


#endif //ABSTRACTVM_ABSTRACTVM_HPP

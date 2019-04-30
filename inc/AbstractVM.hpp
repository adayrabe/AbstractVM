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
		void dump();
		void assertV(IOperand const *operand);
		void getArgs(IOperand const **a, IOperand const **b);

		void add();
		void sub();
		void mul();
		void div();
		void mod();
		void print();
		void exit();
		void tryToTerminate();
};


#endif //ABSTRACTVM_ABSTRACTVM_HPP

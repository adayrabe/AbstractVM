//
// Created by Dayrabekov Artem on 2019-04-26.
//

#include <AbstractVM.hpp>

#include "AbstractVM.hpp"
#include "AbstractVMExceptions.hpp"

AbstractVM::AbstractVM()
{}

AbstractVM::AbstractVM(AbstractVM const &other)
{
	*this = other;
}

//TODO: add correct variable assignments
AbstractVM &AbstractVM::operator=(AbstractVM const &other)
{
	static_cast<void>(other);
	return *this;
}

AbstractVM::~AbstractVM()
{
	while (!_stack.empty())
	{
		delete _stack.top();
		_stack.pop();
	}
}

void AbstractVM::push(const IOperand *operand)
{
	_stack.push(operand);
}

void AbstractVM::pop()
{
	if (_stack.empty())
		throw AbstractVMExceptions::PopOnEmptyStackException();
	_stack.pop();
}

void AbstractVM::dump()
{
	std::stack<IOperand const *> temp = _stack;
	std::cout << "[";
	while (!temp.empty())
	{
		std::cout << temp.top()->toString();
		temp.pop();
		if (!temp.empty())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void AbstractVM::assertV(IOperand const *operand)
{
	if (!(_stack.top()->getType() == operand->getType() && operand->toString() == _stack.top()->toString()))
		throw AbstractVMExceptions::AssertException();
}

void AbstractVM::getArgs(IOperand const **a, IOperand const **b)
{
	if (_stack.empty())
		throw AbstractVMExceptions::NotEnoughArgumentsException();
	*a = _stack.top();
	_stack.pop();
	if (_stack.empty())
		throw AbstractVMExceptions::NotEnoughArgumentsException();
	*b = _stack.top();
	_stack.pop();
}

void AbstractVM::add()
{
	IOperand const *a;
	IOperand const *b;

	getArgs(&a, &b);
	push(*b + *a);
}

void AbstractVM::sub()
{
	IOperand const *a;
	IOperand const *b;

	getArgs(&a, &b);
	push(*b - *a);
}

void AbstractVM::mul()
{
	IOperand const *a;
	IOperand const *b;

	getArgs(&a, &b);
	push(*b * *a);

}

void AbstractVM::div()
{
	IOperand const *a;
	IOperand const *b;

	getArgs(&a, &b);
	push(*b / *a);
}

void AbstractVM::mod()
{
	IOperand const *a;
	IOperand const *b;

	getArgs(&a, &b);
	push(*b % *a);
}




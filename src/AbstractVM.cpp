//
// Created by Dayrabekov Artem on 2019-04-26.
//

#include <AbstractVM.hpp>

#include "AbstractVM.hpp"
#include "AbstractVMExceptions.hpp"
#include "CreateOperand.hpp"

AbstractVM::AbstractVM():_exited(false)
{}

AbstractVM::AbstractVM(AbstractVM const &other)
{
	std::stack <IOperand const *> temp = other._stack;
	CreateOperand t;
	while (!temp.empty())
	{
		_stack.push(t.createOperand(temp.top()->getType(), temp.top()->toString()));
		temp.pop();
	}
	_exited = other._exited;
//	_stack = other._stack;
}

AbstractVM &AbstractVM::operator=(AbstractVM other)
{
//	std::swap(_stack, other._stack);
	_stack.swap(other._stack);
	_exited = other._exited;
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

void AbstractVM::dump()const
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

void AbstractVM::getArg(IOperand const **a)
{
	if (_stack.empty())
		throw AbstractVMExceptions::NotEnoughArgumentsException();
	*a = _stack.top();
	_stack.pop();
}

void AbstractVM::add()
{
	IOperand const *a;
	IOperand const *b;

	getArg(&a);
	getArg(&b);
	push(*b + *a);
}

void AbstractVM::sub()
{
	IOperand const *a;
	IOperand const *b;

	getArg(&a);
	getArg(&b);
	push(*b - *a);
}

void AbstractVM::mul()
{
	IOperand const *a;
	IOperand const *b;

	getArg(&a);
	getArg(&b);
	push(*b * *a);

}

void AbstractVM::div()
{
	IOperand const *a;
	IOperand const *b;

	getArg(&a);
	getArg(&b);
	push(*b / *a);
}

void AbstractVM::mod()
{
	IOperand const *a;
	IOperand const *b;

	getArg(&a);
	getArg(&b);
	push(*b % *a);
}

void AbstractVM::print() const
{
	if (_stack.empty())
		throw AbstractVMExceptions::PrintEmptyStackException();
	if (_stack.top()->getType() != eOperandType::Int8)
		throw AbstractVMExceptions::PrintNotCharException();
	char c = static_cast<char>(atoi(_stack.top()->toString().c_str()));
	std::cout << c << std::endl;
}

void AbstractVM::exit()
{
	if (_exited)
		throw AbstractVMExceptions::TwoExitCommandException();
	_exited = true;
//	::exit(EXIT_SUCCESS);
}

void AbstractVM::tryToTerminate()
{
	if (!_exited)
		throw AbstractVMExceptions::NoExitCommandException();
}

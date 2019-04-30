//
// Created by Dayrabekov Artem on 2019-04-29.
//

#include "functions.hpp"
#include "Parser.hpp"
#include "CreateOperand.hpp"

s_lexeme::s_lexeme(std::string &name, int line) : name(name), line(line){}

s_lexeme::s_lexeme(std::string &name, int line, eOperandType &type, std::string &value): name(name), line(line),
																						  type(type), value(value){}
void doFromArray(std::string &oper, AbstractVM &vm, bool hasError)
{
	void (AbstractVM::*func[])() = {&AbstractVM::pop, &AbstractVM::add, &AbstractVM::sub, &AbstractVM::mul,
									&AbstractVM::div, &AbstractVM::mod, &AbstractVM::exit, &AbstractVM::print,
									&AbstractVM::dump};
	std::vector<std::string> names = {"pop", "add", "sub", "mul", "div", "mod", "exit", "print", "dump", "null"};
	int i = 0;
	while (names[i] != "null")
	{
		if (names[i] == oper)
		{
			if (!hasError || (oper != "print" && oper != "dump"))
				(vm.*func[i])();
			break;
		}
		i++;
	}
	if (names[i] == "null")
		throw ParseExceptions::WrongCommandException();
}

void doOperator(t_lexeme *oper, AbstractVM &vm, bool hasError)
{
	CreateOperand t;

	if (oper->name == "push" || oper->name == "assert")
	{
		const IOperand *operand = t.createOperand(oper->type, oper->value);
		if (oper->name == "push")
			vm.push(operand);
		else
			vm.assertV(operand);
	}
	else
		doFromArray(oper->name, vm, hasError);
}
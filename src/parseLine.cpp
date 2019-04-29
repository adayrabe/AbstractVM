//
// Created by Dayrabekov Artem on 2019-04-29.
//
#include "functions.hpp"

void doFromArray(std::string &oper, AbstractVM &vm)
{
	void (AbstractVM::*func[])() = {&AbstractVM::pop, &AbstractVM::add, &AbstractVM::sub, &AbstractVM::mul,
									&AbstractVM::div, &AbstractVM::mod, &AbstractVM::exit};
	std::vector<std::string> names = {"pop", "add", "sub", "mul", "div", "mod", "exit", "null"};
	int i = 0;
	while (names[i] != "null")
	{
		if (names[i] == oper)
		{
			(vm.*func[i])();
			break;
		}
		i++;
	}
	if (names[i] == "null")
		throw ParseExceptions::WrongCommandException();
}

void doOper(std::string &line, AbstractVM &vm, std::vector<std::string>&messages)
{
	std::string oper = getWord(line);
	if (oper == "push" || oper == "assert")
		doWithNumber(line, oper, vm);
	else if (oper == "print" || oper == "dump")
	{
		if (oper == "print")
			messages.emplace_back(vm.print());
		else
			messages.emplace_back(vm.dump());
	}
	else
		doFromArray(oper, vm);
}

bool parseLine(std::string &line, std::vector<std::string>&messages, bool readFromCin, AbstractVM &vm)
{
	skipSpaces(line);
	if (line[0])
	{
		if (line[0] == COMMENT_CHAR && line[1] == COMMENT_CHAR && readFromCin)
			return false;
		doOper(line, vm, messages);
	}
	skipSpaces(line);
	if (line[0] && line[0] != COMMENT_CHAR)
		throw ParseExceptions::WrongSymbolsAtTheEndOfLineException();
	return true;
}
//
// Created by Dayrabekov Artem on 2019-04-29.
//

#include "parseLine.hpp"
#include <vector>

void skipSpaces(std::string &temp)
{
	size_t i = 0;
	while (temp[i] && isspace(temp[i]))
		i++;
	temp = temp.erase(0, i);
}

std::string getWord(std::string &line)
{
	std::string oper;
	size_t i = 0;
	for (; line[i] && !isspace(line[i]) && line[i] != COMMENT_CHAR; i++)
		oper[i] = line[i];
	line = line.erase(0, i);
	return oper;
}

void getFromArray(std::string &oper, AbstractVM &vm)
{
	void (AbstractVM::*func[])() = {&AbstractVM::pop, &AbstractVM::add, &AbstractVM::sub, &AbstractVM::mul,
									&AbstractVM::div, &AbstractVM::mod};
	std::vector<std::string> names = {"pop", "add", "sub", "mul", "div", "mod", "null"};
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
		throw;
}

void doOper(std::string &line, AbstractVM &vm, std::vector<std::string>&messages)
{
	std::string oper = getWord(line);
	if (oper == "push" || oper == "assert")
	{
		messages.push_back("s");
	}
	else if (oper == "print" || oper == "dump")
	{

	}
	else
		getFromArray(line, vm);
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
		throw;
	return true;
}
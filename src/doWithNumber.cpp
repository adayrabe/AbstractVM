//
// Created by Dayrabekov Artem on 2019-04-29.
//
#include "functions.hpp"

eOperandType getType(std::string &str)
{
	std::string type;
	std::vector<std::string> types = {"int8", "int16", "int32", "float", "double", "null"};
	size_t i = 0;
	for (; str[i] && str[i] != '('; i++)
		type += str[i];
	if (str[i]!='(')
		throw ParseExceptions::NoOpenBracketException();
	str = str.erase(0, i + 1);
	i = 0;
	while (types[i] != "null")
	{
		if (types[i] == type)
			return static_cast<eOperandType>(i);
		i++;
	}
	throw ParseExceptions::WrongOperandExcetion();
}

std::string getNum(std::string &line)
{
	std::string num;
	size_t i = 0;
	for (; line[i] && line[i] != ')'; i++)
		num += line[i];
	if (line[i] != ')')
		throw ParseExceptions::NoClosingBracketException();
	line = line.erase(0, i + 1);
	return num;
}

void doWithNumber(std::string &line, std::string &oper, AbstractVM &vm)
{
	skipSpaces(line);
	std::string value = getWord(line);
	CreateOperand t;
	eOperandType type = getType(value);
	std::string num = getNum(value);
	const IOperand* operand = t.createOperand(type, num);
	if (oper == "push")
		vm.push(operand);
	else
		vm.assertV(operand);
}
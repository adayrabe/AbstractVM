//
// Created by Dayrabekov Artem on 2019-04-30.
//

#include <Parser.hpp>

#include "Parser.hpp"
#include "functions.hpp"
#include "CreateOperand.hpp"


Parser::Parser(Parser const &other)
{
	*this = other;
}

//TODO: add correct variable assignments
Parser &Parser::operator=(Parser const &other)
{
	static_cast<void>(other);
	return *this;
}

Parser::~Parser()
{
	delete _vm;
	for (size_t i = 0; i < _operands.size(); i++)
		delete _operands[i];
}

Parser::Parser(bool fromStdIn, t_flags &flags):_fromStdin(fromStdIn)
{
	_flags.doOperations = flags.doOperations;
	_flags.showErrors = flags.showErrors;
	_flags.printStack = flags.printStack;
	_vm = new AbstractVM();
}

bool Parser::parse(std::istream &is)
{
	std::string line;
	int l = 0;

	while (getline(is, line))
	{
		try
		{
			l++;
			if (!parseLine(line, l))
				break;
		}
		catch (std::exception &e)
		{
			std::cout << "Error at line " << l << " - " << e.what() << std::endl;
			if (!_flags.showErrors)
				return false;
		}
	}
	if (_flags.doOperations || _flags.printStack)
	{
		try
		{
			_vm->tryToTerminate();
		}
		catch (std::exception &e)
		{
			std::cout << "Error - " << e.what() << std::endl;
			if (!_flags.showErrors)
				return false;
		}
	}
	return true;
}

bool Parser::parseLine(std::string &line, int l)
{
	skipSpaces(line);
	if (line[0])
	{
		if (line[0] == COMMENT_CHAR && line[1] == COMMENT_CHAR && _fromStdin)
			return false;
		addOper(line, l);
	}
	skipSpaces(line);
	if (line[0] && line[0] != COMMENT_CHAR)
		throw ParseExceptions::WrongSymbolsAtTheEndOfLineException();
	return true;
}

void Parser::addOper(std::string &line, int l)
{
	std::string oper = getWord(line);
	if (oper == "push" || oper == "assert")
		doWithNumber(line, oper, l);
	else
	{
		std::vector<std::string> names = {"pop", "add", "sub", "mul", "div", "mod", "exit", "print", "dump", "null"};
		int i = 0;
		while (names[i] != "null" && names[i] != oper)
			i++;
		if (names[i] == "null")
			throw ParseExceptions::WrongCommandException();
		t_lexeme *temp = new t_lexeme(oper, l);

		if (_flags.printStack || _flags.doOperations)
			doOperator(temp, *_vm);
		else
			_operands.emplace_back(temp);
	}
}

std::string Parser::getWord(std::string &line)
{
	std::string oper;
	size_t i = 0;
	for (; line[i] && !isspace(line[i]) && line[i] != COMMENT_CHAR; i++)
		oper += line[i];
	line = line.erase(0, i);
	return oper;
}

void Parser::skipSpaces(std::string &temp)
{
	size_t i = 0;
	while (temp[i] && isspace(temp[i]))
		i++;
	temp = temp.erase(0, i);
}

void Parser::doWithNumber(std::string &line, std::string &oper, int l)
{
	skipSpaces(line);
	std::string value = getWord(line);
	eOperandType type = getType(value);
	std::string num = getNum(value);
	t_lexeme *temp = new t_lexeme(oper, l, type, num);
	if (_flags.doOperations || _flags.printStack)
		doOperator(temp, *_vm);
	else
		_operands.emplace_back(temp);
}

eOperandType Parser::getType(std::string &str)
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

std::string Parser::getNum(std::string &line)
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

const std::vector<t_lexeme *> &Parser::getOperands() const
{
	return _operands;
}

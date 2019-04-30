//
// Created by Dayrabekov Artem on 2019-04-29.
//

#ifndef ABSTRACTVM_PARSELINE_HPP
#define ABSTRACTVM_PARSELINE_HPP

#include <iostream>
#define COMMENT_CHAR ';'
#include "AbstractVM.hpp"
#include <vector>
#include "ParseExceptions.hpp"
//#include "Parser.hpp"

typedef struct 	s_lexeme
{
	std::string name;
	int line;
	eOperandType type;
	std::string value;
	s_lexeme(std::string &name, int line);
	s_lexeme(std::string &name, int line, eOperandType &type, std::string &value);
}				t_lexeme;

typedef struct 	s_flags
{
	bool showErrors = false;
	bool printStack = false;
	bool doOperations = false;
}				t_flags;

void doOperator(t_lexeme *oper, AbstractVM &vm);

#endif //ABSTRACTVM_PARSELINE_HPP

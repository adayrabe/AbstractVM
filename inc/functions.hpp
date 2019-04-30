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
	bool showErrors;
	bool printStack ;
	bool doOperaions;
}				t_flags;

void doOperator(t_lexeme *oper, AbstractVM &vm);
//bool parseLine(std::string &line, std::vector<std::string> &messages, bool readFromCin, AbstractVM &vm, t_flags &flags);
//void doWithNumber(std::string &line, std::string &oper, AbstractVM &vm);
//void skipSpaces(std::string &temp);
//std::string getWord(std::string &line);
//void parseFile(std::string &str, t_flags &flags);
//void parse(std::istream &is, t_flags &flags, bool readFromCin);

#endif //ABSTRACTVM_PARSELINE_HPP

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
#include "CreateOperand.hpp"

bool parseLine(std::string &line, std::vector<std::string>&messages, bool readFromCin, AbstractVM &vm);
void doWithNumber(std::string &line, std::string &oper, AbstractVM &vm);
void skipSpaces(std::string &temp);
std::string getWord(std::string &line);

#endif //ABSTRACTVM_PARSELINE_HPP

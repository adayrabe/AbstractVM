//
// Created by Dayrabekov Artem on 2019-04-29.
//

#ifndef ABSTRACTVM_PARSELINE_HPP
#define ABSTRACTVM_PARSELINE_HPP

#include <iostream>
#define COMMENT_CHAR ';'
#include "AbstractVM.hpp"

bool parseLine(std::string &line, std::vector<std::string>&messages, bool readFromCin, AbstractVM &vm);

#endif //ABSTRACTVM_PARSELINE_HPP

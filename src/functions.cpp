//
// Created by Dayrabekov Artem on 2019-04-29.
//

#include "functions.hpp"

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
		oper += line[i];
	line = line.erase(0, i);
	return oper;
}

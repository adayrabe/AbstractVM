//
// Created by Dayrabekov Artem on 2019-04-30.
//

#ifndef ABSTRACTVM_PARSER_HPP
#define ABSTRACTVM_PARSER_HPP


#include <iostream>
#include "functions.hpp"

class Parser
{
	private:
		bool _fromStdin;
		std::vector<t_lexeme *> _operands;
		t_flags _flags;
		AbstractVM *_vm;

	public:
		Parser(bool fromStdIn, t_flags &flags);

		Parser(Parser const &other);

		Parser &operator=(Parser const &other);

		virtual ~Parser();

		bool parse(std::istream &is);
		bool parseLine(std::string &line, int l);
		void addOper(std::string &line, int l);
		void skipSpaces(std::string &temp);
		std::string getWord(std::string &line);
		void doWithNumber(std::string &line, std::string &oper, int l);
		eOperandType getType(std::string &str);
		std::string getNum(std::string &line);

		const std::vector<t_lexeme *> &getOperands() const;

};


#endif //ABSTRACTVM_PARSER_HPP

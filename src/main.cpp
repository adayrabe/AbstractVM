
#include <iostream>
#include "IOperand.hpp"
#include "CreateOperand.hpp"
#include <stack>
#include "AbstractVM.hpp"
#include <float.h>
#include "functions.hpp"
#include "Parser.hpp"
#include <fstream>

void checkFlag(std::string const &str, t_flags *flags)
{
	if (str == "-e")
		flags->showErrors = true;
	else if (str == "-s")
		flags->printStack = true;
	else
	{
		std::cout << "Error - unknown flag. Available flags:" << std::endl;
		std::cout << "-e : Shows all of the possible errors" << std::endl;
		std::cout << "-s : Shows the operator that is executed and the stack after this operator" << std::endl;

		exit(EXIT_FAILURE);
	}
}

std::vector<std::string> parseFlags(int ac, char **av, t_flags *flags)
{
	std::vector <std::string> res;
	for (int i = 1; i < ac; i++)
	{
		if (av[i][0] == '-')
			checkFlag(av[i], flags);
		else
			res.emplace_back(av[i]);
	}
	return res;
}

void parseInput(bool fromStdIn, t_flags &flags, std::istream &is)
{
	Parser p(fromStdIn, flags);
	AbstractVM vm;

	p.parse(is);
	for (size_t i = 0; i < p.getOperands().size(); i++)
	{
		doOperator(p.getOperands()[i], vm);
	}
	try
	{
		vm.tryToTerminate();
	}
	catch (std::exception &e)
	{
		std::cout << "Error - " << e.what() << std::endl;
	}

}

void parseFile(std::string &str, t_flags &flags)
{
	std::ifstream ifs(str);
	if (ifs)
		parseInput(false, flags, ifs);
	else
		std::cout << "Error - " << strerror(errno) << std::endl;
}

int main(int argc, char **argv)
{
	t_flags flags;
	flags.printStack = false;
	flags.showErrors = false;
	std::vector <std::string> files = parseFlags(argc, argv, &flags);
	if (files.empty())
		parseInput(true, flags, std::cin);
	else
	{
		for (auto v: files)
			parseFile(v, flags);
	}
	return 0;
}
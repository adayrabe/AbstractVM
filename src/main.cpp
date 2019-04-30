
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
	else if (str == "-o")
		flags->doOperations = true;
	else
	{
		std::cout << "Error - unknown flag. Available flags:" << std::endl;
		std::cout << "-e : Shows all of the possible errors" << std::endl;
		std::cout << "-s : Shows the operator that is executed and the stack after this operator" << std::endl;
		std::cout << "-o : Does the operator right away without waiting for the end of an input" << std::endl;

		exit(EXIT_FAILURE);
	}
	if (flags->printStack && flags->doOperations)
	{
		std::cout << "Error - only one of two flags -s or -o can be included" << std::endl;
		exit (EXIT_FAILURE);
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

	if (!p.parse(is))
		return ;
	bool hasError = p.isHasError();
	for (size_t i = 0; i < p.getOperands().size(); i++)
	{
		try
		{
			doOperator(p.getOperands()[i], vm, hasError);
		}
		catch (std::exception &e)
		{
			std::cout << "Error at line " << p.getOperands()[i]->line << " - " << e.what() << std::endl;
			hasError = true;
			if (!flags.showErrors)
				return ;
		}
	}
	if (!flags.doOperations && !flags.printStack)
	{
		try
		{
			vm.tryToTerminate();
		}
		catch (std::exception &e)
		{
			std::cout << "Error - " << e.what() << std::endl;
		}
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

	std::vector <std::string> files = parseFlags(argc, argv, &flags);
	if (files.empty())
		parseInput(true, flags, std::cin);
	else
	{
		if (files.size() < 2)
			parseFile(files[0], flags);
		else
			for (auto v: files)
			{
				std::cout << "FILE " << v << std::endl;
				parseFile(v, flags);
				std::cout << "===========================================" << std::endl;
			}
	}
	return 0;
}
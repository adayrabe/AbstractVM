
#include <iostream>
#include "IOperand.hpp"
#include "CreateOperand.hpp"
#include <stack>
#include "AbstractVM.hpp"
#include <float.h>
#include <fstream>
#include <vector>
#include "parseLine.hpp"
//#include <errno.h>


void parse(std::istream &is, bool readFromCin)
{
	std::string line;
	std::vector<std::string> messages;
	AbstractVM vm;

	while (getline(is, line))
	{
		try
		{
			if (!parseLine(line, messages, readFromCin, vm))
				break;
		}
		catch (std::exception &e)
		{
			std::cout << "Error - " << e.what() << std::endl;
			break;
		}
	}
	try
	{
		vm.tryToTerminate();
	}
	catch (std::exception &e)
	{
		std::cout << "Error - " << e.what() << std::endl;
		return ;
	}
}


int main(int argc, char **argv)
{
	if (argc == 0)
		parse(std::cin, true);
	else if (argc == 1)
	{
		std::ifstream ifs(argv[1]);
		if (ifs)
		{
			parse(ifs, false);
		}
		else
			std::cout << "Error - " << strerror(errno) << std::endl;
	}
	else
		std::cout << "Too many arguments" << std::endl;
	return 0;
}
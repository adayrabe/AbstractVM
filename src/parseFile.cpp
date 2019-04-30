//
// Created by Dayrabekov Artem on 2019-04-30.
//
#include "functions.hpp"
#include <fstream>


//void printMessages(std::vector<std::string> &messages)
//{
//	for (auto i : messages)
//		std::cout << i;
//}

//void parse(std::istream &is, t_flags &flags, bool readFromCin)
//{
//	std::string line;
//	std::vector<std::string> messages;
//	AbstractVM vm;
//	int l = 1;
//
//	while (getline(is, line))
//	{
//		try
//		{
//			if (!parseLine(line, messages, readFromCin, vm, flags))
//				break;
//			l++;
//		}
//		catch (std::exception &e)
//		{
//			std::cout << "Error at line " << l << " - " << e.what() << std::endl;
//			if (!flags.showErrors)
//				return ;
//		}
//	}
//	try
//	{
//		vm.tryToTerminate();
//	}
//	catch (std::exception &e)
//	{
//		std::cout << "Error - " << e.what() << std::endl;
//		if (!flags.showErrors)
//			return ;
//	}
//}


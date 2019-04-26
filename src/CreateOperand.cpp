//
// Created by Dayrabekov Artem on 2019-04-26.
//

#include <CreateOperand.hpp>

#include "CreateOperand.hpp"
#include "Operand.hpp"

const IOperand * CreateOperand::createInt8(std::string const &value) const
{
	return new Operand<eOperandType::Int8>(value);
}

const IOperand * CreateOperand::createInt16(std::string const &value) const
{
return new Operand<eOperandType::Int16>(value);
}

const IOperand * CreateOperand::createInt32(std::string const &value) const
{
return new Operand<eOperandType::Int32>(value);
}

const IOperand * CreateOperand::createFloat(std::string const &value) const
{
return new Operand<eOperandType::Float>(value);
}

const IOperand * CreateOperand::createDouble(std::string const &value) const
{
	return new Operand<eOperandType::Double>(value);
}

const IOperand * CreateOperand::createOperand(eOperandType type, std::string const &value) const
{
	IOperand const *(CreateOperand::*funcs[])(std::string const &value) const =
	{&CreateOperand::createInt8, &CreateOperand::createInt16, &CreateOperand::createInt32, &CreateOperand::createFloat,
  &CreateOperand::createDouble};
	return (this->*funcs[static_cast<int>(type)])(value);
}
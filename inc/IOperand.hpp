//
// Created by Dayrabekov Artem on 2019-04-25.
//

#ifndef ABSTRACTVM_IOPERAND_HPP
#define ABSTRACTVM_IOPERAND_HPP

#include <iostream>
#include "OperandExceptions.hpp"

//#include "CreateOperand.hpp"

enum class eOperandType{Int8, Int16, Int32, Float, Double};

class IOperand
{
	public:
		virtual int				getPrecision() const = 0;
		virtual eOperandType	getType() const = 0;

		virtual IOperand const *operator+(IOperand const &rhs) const = 0; // Sum
		virtual IOperand const * operator-( IOperand const &rhs ) const = 0; // Difference
		virtual IOperand const * operator*( IOperand const &rhs ) const = 0; // Product
		virtual IOperand const * operator/( IOperand const &rhs ) const = 0; // Quotient
		virtual IOperand const * operator%( IOperand const &rhs ) const = 0; // Modulo

		virtual std::string const & toString() const = 0; // String representation of the instance
		virtual ~IOperand() = default;
};

#endif //ABSTRACTVM_IOPERAND_HPP

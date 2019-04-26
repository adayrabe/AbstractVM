//
// Created by Dayrabekov Artem on 2019-04-26.
//

#ifndef ABSTRACTVM_CREATEOPERAND_HPP
#define ABSTRACTVM_CREATEOPERAND_HPP


#include <iostream>
#include "IOperand.hpp"

class CreateOperand
{
	private:
		IOperand const * createInt8( std::string const & value ) const ;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
	public:
		CreateOperand() = default;
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;

};


#endif //ABSTRACTVM_CREATEOPERAND_HPP

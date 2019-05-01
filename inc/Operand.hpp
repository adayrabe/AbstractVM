//
// Created by Dayrabekov Artem on 2019-04-25.
//
#include "IOperand.hpp"
#include <float.h>
//#include <string>
#include "CreateOperand.hpp"
#include <sstream>
#include <iomanip>

template <eOperandType T>
class Operand : public IOperand
{
	private:
		eOperandType _type;
		long double _value;
		std::string _str;
		int _precision;

	public:
		Operand<T>() = delete;
		explicit Operand<T>(std::string const &value) : _type(T)
		{
			long double temp = checkNum(value, _type);

			checkValue(temp, _type);
			_value = temp;
			_precision = static_cast<int>(_type);
		}

		Operand<T>(Operand<T> const &other) = default;

		int getPrecision() const override
		{
			return _precision;
		}

		eOperandType getType() const override
		{
			return _type;
		}

		eOperandType makeType(IOperand const &other) const
		{
			eOperandType type;
			if (_precision > other.getPrecision())
				type = _type;
			else
				type = other.getType();
			return type;
		}

		std::string makeString(long double num, eOperandType type, bool precision) const
		{
			if (type == eOperandType::Int8 || type == eOperandType::Int16 || type == eOperandType::Int32)
				return std::to_string(static_cast<long>(num));
			else
			{
				std::ostringstream oss;
				std::string res;

				if (type == eOperandType::Float && precision)
					oss << std::scientific << std::setprecision(7) << num;
				else if (type == eOperandType::Double && precision)
					oss << std::scientific << std::setprecision(16) << num;
				else
					oss << std::fixed << num;
				res = oss.str();
				return res;
			}
		}

		bool getPrecision(unsigned long num, eOperandType type) const
		{
			if (type == eOperandType::Float && (num > 999999 || num < 0.00000001))
				return true;
			if (type == eOperandType::Double && (num > 999999999999999 || num < 0.00000000000001))
				return true;
			return false;
		}

		const IOperand *operator+(IOperand const &rhs) const override
		{
			long double temp = stold(rhs.toString());
			temp = _value + temp;

			eOperandType type = makeType(rhs);
			CreateOperand t;
			std::string str = makeString(temp, type, getPrecision(temp, type));
			return t.createOperand(type, str);
		}

		const IOperand *operator-(IOperand const &rhs) const override
		{
			long double temp = stold(rhs.toString());
			temp = _value - temp;

			eOperandType type = makeType(rhs);
			CreateOperand t;
			std::string str = makeString(temp, type, getPrecision(temp, type));
			return t.createOperand(type, str);
		}

		const IOperand *operator*(IOperand const &rhs) const override
		{
			long double temp = stold(rhs.toString());
			temp = _value * temp;

			eOperandType type = makeType(rhs);
			std::string str = makeString(temp, type, getPrecision(temp, type));
			CreateOperand t;
			return t.createOperand(type, str);
		}

		const IOperand *operator/(IOperand const &rhs) const override
		{
			long double temp = stold(rhs.toString());
			if (temp == 0)
				throw OperandExceptions::ZeroDivisionException();

			temp = _value / temp;
			eOperandType type = makeType(rhs);
			std::string str = makeString(temp, type, getPrecision(temp, type));
			CreateOperand t;
			return t.createOperand(type, str);
		}

		const IOperand *operator%(IOperand const &rhs) const override
		{
			if (rhs.getType() == eOperandType::Float || rhs.getType() == eOperandType::Double)
				throw OperandExceptions::FloatingPointModuloOfException();
			if (_type == eOperandType::Float || _type == eOperandType::Double)
				throw OperandExceptions::FloatingPointModuloFromException();

			int temp = stoi(rhs.toString());
			if (temp == 0)
				throw OperandExceptions::ZeroModuloException();

			temp = static_cast<int>(_value) % temp;
			eOperandType type = makeType(rhs);
			std::string str = makeString(temp, type, getPrecision(temp, type));
			CreateOperand t;
			return t.createOperand(type, str);
		}

		const std::string &toString() const override
		{
			return _str;
		}

		~Operand() override = default;

		long double checkNum(std::string str, eOperandType type)
		{
			std::istringstream ss(str);
			long double res;
			ss >> res;
			int i = 0;
			if (str[i] == '-')
				i++;
			if (!isnumber(str[i]))
				throw OperandExceptions::WrongCharacterException();
			while (isnumber(str[i]))
				i++;
			if (type == eOperandType::Int8 || type == eOperandType::Int16 || type == eOperandType::Int32)
			{
				if (str[i] == '.')
					throw OperandExceptions::WrongCharacterException();
				_str = str;
			}
			else
			{
				if (str[i] == '.')
				{
					i++;
					if (!isnumber(str[i]))
						throw OperandExceptions::WrongCharacterException();
					while (isnumber(str[i]))
						i++;
					if (str[i] == 'e')
					{
						i++;
						if (str[i] != '+' && str[i] != '-')
							throw OperandExceptions::WrongCharacterException();
						i++;
						while (isnumber(str[i]))
							i++;
					}
				}
				_str = makeString(res, type, getPrecision(res, type));
			}
			while (isspace(str[i]))
				i++;
			if (str[i])
				throw OperandExceptions::WrongCharacterException();
			return res;
		}

		void checkValue(long double temp, eOperandType type)
		{
			switch (type)
			{
				case eOperandType::Int8:
					if (temp > CHAR_MAX || temp < CHAR_MIN)
						throw OperandExceptions::ValueOverflowException();
					break;
				case eOperandType::Int16:
					if (temp > SHRT_MAX || temp < SHRT_MIN)
						throw OperandExceptions::ValueOverflowException();
					break;
				case eOperandType::Int32:
					if (temp > INT_MAX || temp < INT_MIN)
						throw OperandExceptions::ValueOverflowException();
					break;
				case eOperandType::Float:
					if (temp > FLT_MAX || temp < -FLT_MAX)
						throw OperandExceptions::ValueOverflowException();
					if ((temp > 0 && temp < FLT_MIN) || (temp < 0 && temp > -FLT_MIN))
						throw OperandExceptions::ValueUnderflowException();
					break;
				case eOperandType::Double:
					if (temp > DBL_MAX || temp < -DBL_MAX)
						throw OperandExceptions::ValueOverflowException();
					if ((temp > 0 && temp < DBL_MIN) || (temp < 0 && temp > -DBL_MIN))
						throw OperandExceptions::ValueUnderflowException();
					break;
			}
		}
};

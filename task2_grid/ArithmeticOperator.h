// Oytun Demirbilek
// 150150032
#ifndef ARITHMETICOPERATOR_H
#define ARITHMETICOPERATOR_H
#include "pch.h"
#include "Operator.h"

class ArithmeticOperator: public Operator
{
	char sign;
public:
	ArithmeticOperator(int x, int y, int size, char sign);
	char get_sign();
	void print_operator();
	~ArithmeticOperator();
};

#endif
// Oytun Demirbilek
// 150150032
#include "pch.h"
#include "OperatorGrid.h"
#include "ArithmeticOperator.h"
#include "Operator.h"
#include <iostream>
using namespace std;

ArithmeticOperator::ArithmeticOperator(int x, int y, int size, char sign)
{
	if (sign == '+' || sign == '-' || sign == 'x' || sign == '/') {
		this->sign = sign;
		this->set_x(x);
		this->set_y(y);
		this->set_size(size);
	}
	else {
		cout << "SIGN parameter is invalid!" << endl;
	}
}
char ArithmeticOperator::get_sign() {

	return this->sign;
}
void ArithmeticOperator::print_operator() {
	cout << "ARITHMETIC_OPERATOR[" << this->get_sign() << "], CENTER_LOCATION[" << this->get_x() << ", " << this->get_y() << "], SIZE[" << this->get_size() << "]" << endl;
}

ArithmeticOperator::~ArithmeticOperator()
{
}


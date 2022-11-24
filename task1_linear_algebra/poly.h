//Oytun Demirbilek
//150150032
#ifndef POLY_H
#define POLY_H
#include <iostream>
using namespace std;

class poly
{
	public:
		poly();
		poly(int);
		poly operator+(poly&);
		poly operator*(poly&);
		void append(double* newvalues);
		friend ostream& operator<<(ostream&, const poly&);
		~poly();
	private:
		int dimension;
		double* polarray;
};
#endif
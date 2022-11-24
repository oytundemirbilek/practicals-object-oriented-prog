//Oytun Demirbilek
//150150032
#include "pch.h"
#include "poly.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

poly::poly() {
}
poly::poly(int newpoly)
{
	this->polarray = (double*)malloc(dimension * sizeof(double));//allocating memory for the array
	polarray = new double[newpoly];
	this->dimension = newpoly;//copy constructor
}

poly poly::operator+(poly &adding) {//OVERLOAD + SIGN
	poly total;
	int dim;
	if (this->dimension < adding.dimension) {
		dim = this->dimension;//getting smaller dimension for afterwards
		total.polarray = (double*)malloc(adding.dimension * sizeof(double));
		total.dimension = adding.dimension;//getting the dimension of the total
		for (int i = 0; i < adding.dimension; i++)total.polarray[i] = adding.polarray[i];//passing all values to the total
	}
	else {
		dim = adding.dimension;
		total.polarray = (double*)malloc(this->dimension * sizeof(double));
		total.dimension = this->dimension;//getting dimensions
		for (int i = 0; i < this->dimension; i++)total.polarray[i] = polarray[i];//passing values to the total
	}

	for (int i = 0; i < dim; i++) {
		total.polarray[i] = polarray[i] + adding.polarray[i];//adding small one to the big one
	}
	return total;
}

poly poly::operator*(poly &dot) {//OVERLOAD * SIGN
	poly total;
	total.dimension = this->dimension + dot.dimension - 1;//dimension is the total of the largest indexes
	total.polarray = (double*)malloc(total.dimension * sizeof(double));
	for (int i = 0; i < total.dimension; i++)total.polarray[i] = 0;//setting all values to the zeros
	for (int i = 0; i < this->dimension; i++) {
		for (int j = 0; j < dot.dimension; j++) {
			total.polarray[i+j] = total.polarray[i+j] + polarray[i] * dot.polarray[j];//iterative adder
		}
	}
	return total;
}

void poly::append(double* values) {
	
	for (int i = 0; i < this->dimension; i++) {
		this->polarray[i] = values[i];//passing values
	}
}

ostream& operator<<(ostream& out, const poly& poly)//OVERLOADING << FOR OUTPUTS
{
	out << "(";
	for (int i = poly.dimension - 1; i >=0 ; i--) {
		if (poly.polarray[i] > 1) {
			if(i > 1)out << poly.polarray[i] << "x" << "^" << i;
			else if(i == 1)out << poly.polarray[i] << "x";
			else if(i == 0)out << poly.polarray[i];
		}
		else if (poly.polarray[i] == 1) {
			if(i > 1)out << "x" << "^" << i;
			else if (i == 1)out << "x";
			else out << "1";
		}
		if (i != 0)out << " + ";
	}
	out << ")";
	return out;
}

poly::~poly()
{
}

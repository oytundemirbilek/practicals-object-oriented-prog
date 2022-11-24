//Oytun Demirbilek
//150150032
#include "pch.h"
#include "vector.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

vector::vector() {
}
vector::vector(int newvector)
{
	this->vecarray = (double*)malloc(dimension * sizeof(double));//allocating memory for the array
	vecarray = new double[newvector];
	this->dimension = newvector;
}

vector vector::operator+(vector &adding) {//OPERATOR OVERLOADING FOR + SIGN
	vector total;
	total.vecarray = (double*)malloc(this->dimension * sizeof(double));
	if(this->dimension == adding.dimension){
		for (int i = 0; i < this->dimension; i++) {

			total.vecarray[i] = vecarray[i] + adding.vecarray[i];//adding all values with same index
		}
		total.dimension = this->dimension;
		return total;
	}
	else {
		cout << "Dimension error return -1";//Exception handling
		return -1;
	}
}

vector vector::operator*(int scalar) {//OPERATOR OVERLOADING * FOR SCALAR MULTIPLICATION
	vector total;
	total.vecarray = (double*)malloc(this->dimension * sizeof(double));
	for (int i = 0; i < this->dimension; i++) {
		total.vecarray[i] = vecarray[i] * scalar;//Multiplying all elements with the same value
	}
	total.dimension = this->dimension;
	return total;
}

double vector::operator*(vector &dot) {//OPERATOR OVERLOADING * FOR DOT PRODUCT
	double total = 0;
	if (this->dimension == dot.dimension) {
		for (int i = 0; i < this->dimension; i++) {
			total = total + vecarray[i] * dot.vecarray[i];//Multiplying all values with same index and sum
		}
		
		return total;
	}
	else {
		cout << "Dimension error return -1";//Exception handling
		return -1;
	}
}

void vector::append(double* values) {
	
	for (int i = 0; i < this->dimension; i++) {
		this->vecarray[i] = values[i];
	}
}

ostream& operator<<(ostream& out, const vector& vec)//OPERATOR OVERLOADING << FOR THE OUTPUTS
{
	out << "(";
	for (int i = 0; i < vec.dimension; i++) {
		if (i != vec.dimension - 1)out << vec.vecarray[i] << ", ";
		else out << vec.vecarray[i] << ")";
	}
	return out;
}

vector::~vector()
{
}


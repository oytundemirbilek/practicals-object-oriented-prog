//Oytun Demirbilek
//150150032

#include "pch.h"
#include "vector.h"
#include "poly.h"
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <string.h>

using namespace std;
int main()
{
	int operand1, operand2; //operands for operations
	int veccount, dimension, choice=4; //vector count, dimensions and choice from the user
	int polcount;//polynomial count

	double value;//temp variable
	char op;//operator: +, * or .

	FILE* fpv = fopen("Vector.txt", "r");
	FILE* fpp = fopen("Polynomial.txt", "r");

	//CREATE VECTOR ARRAY
	fscanf(fpv, "%d", &veccount);
	vector* vecs = (vector*)malloc(veccount * sizeof(vector));//array of vectors
	double* temparray = (double*)malloc(1 * sizeof(double));//initial memory for the temporary array

	for (int i = 0; i < veccount; i++) {
		fscanf(fpv, "%d", &dimension);
		temparray = (double*)malloc(dimension * sizeof(double));//getting dimension
		vecs[i] = dimension;//vectors are constructing
		for (int j = 0; j < dimension; j++) {
			fscanf(fpv, "%lf", &value);
			temparray[j] = value;//values in temparray
		}
		vecs[i].append(temparray);//from temparray to directly to the vector
	}

	//CREATE POLYNOMIAL ARRAY
	fscanf(fpp, "%d", &polcount);
	poly* polys = (poly*)malloc(polcount * sizeof(poly));
	for (int i = 0; i < polcount; i++) {
		fscanf(fpp, "%d", &dimension);
		temparray = (double*)malloc((dimension + 1)* sizeof(double));
		polys[i] = dimension + 1;
		for (int j = 0; j < dimension + 1; j++) {
			fscanf(fpp, "%lf", &value);
			temparray[dimension - j] = value;//order is backwards for dimension
		}
		polys[i].append(temparray);//get values
	}

	while (choice != 0) {
		if (choice == 1) {
			cout << "Vectors: " << endl;
			for (int i = 0; i < veccount; i++) {
				cout << i + 1 << ". ";
				cout << vecs[i] << endl;
			}
			cout << endl;
			cout << "Polynomials: " << endl;
			for (int i = 0; i < polcount; i++) {
				cout << i + 1 << ". ";
				cout << polys[i] << endl;
			}
			cout << endl;
		}
		else if (choice == 2) {
			cout << "Which polynomial operation would you like to do? (+: addition, *:multiplication):" << endl;
			cin >> operand1 >> op >> operand2;
			cout << polys[operand1 - 1];
			if (op == '+') {
				cout << " + " << polys[operand2 - 1] << " = " << polys[operand1 - 1] + polys[operand2 - 1] << endl;
			}
			if (op == '*') {
				cout << " * " << polys[operand2 - 1] << " = " << polys[operand1 - 1] * polys[operand2 - 1] << endl;
			}
			cout << endl;
		}
		else if (choice == 3) {
			cout << "Which vector operation would you like to do? (+: addition, *:scalar multiplication, .:dot product):" << endl;
			cin >> operand1 >> op >> operand2;
			cout << vecs[operand1 - 1];
			if (op == '+') {
				cout << " + " << vecs[operand2 - 1] << " = " << vecs[operand1 - 1] + vecs[operand2 - 1] << endl;
			}
			if (op == '*') {
				cout << " * " << operand2 << " = " << vecs[operand1 - 1] * operand2 << endl;
			}
			if (op == '.') {
				cout << " . " << vecs[operand2 - 1] << " = " << vecs[operand1 - 1] * vecs[operand2 - 1] << endl;
			}
			cout << endl;
		}
		else if (choice == 4) {
			cout << "Possible Actions: " << endl;
			cout << "1. Print Polynomial and Vector lists" << endl;
			cout << "2. Do a polynomial operation" << endl;
			cout << "3. Do a vector operation" << endl;
			cout << "4. Help: Print possible actions" << endl;
			cout << "0. Exit the program" << endl;
		}

		cout << "Enter an option: ";
		scanf("%d", &choice);
	}
	return 0;
	
}


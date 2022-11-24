// Oytun Demirbilek
// 150150032
#include "pch.h"
#include "OperatorGrid.h"
#include "ArithmeticOperator.h"
#include "Operator.h"
#include <iostream>

using namespace std;

OperatorGrid::OperatorGrid(int rows, int cols)
{
	this->grid_rows = rows;
	this->grid_cols = cols;
	//getting memory allocated for the grid
	grid = new char*[rows];
	for (int i = 0; i < rows; i++) grid[i] = new char[cols];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)grid[i][j] = '0';
	}

	gridindex = new int*[rows];
	for (int i = 0; i < rows; i++) gridindex[i] = new int[cols];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)gridindex[i][j] = -1;
	}
}

bool OperatorGrid::place_operator(ArithmeticOperator * operatorOb)
{
	cerror = 0;
	berror = 0;
	int centerrow = operatorOb->get_x() - 1;
	int centercol = operatorOb->get_y() - 1;
	int size = operatorOb->get_size();
	char sign = operatorOb->get_sign();
	//check signs if there is a conflict or border error, return false if there is any
	if (sign == '+') {
		for (int i = 0; i < size + 1; i++) {
			if (centerrow - i < 0 || centerrow + i >= this->grid_rows || centercol - i < 0 || centercol + i >= this->grid_cols) {
				berror = 1;
			}
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow][centercol - i] != -1) {
				cerror = 1;
			}
			if (centercol - i - 1 < 0)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow][centercol + i] != -1) {
				cerror = 1;
			}
			if (centercol + i + 1 >= this->grid_rows - 1)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow - i][centercol] != -1) {
				cerror = 1;
			}
			if (centerrow - i - 1 < 0)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow + i][centercol] != -1) {
				cerror = 1;
			}
			if (centerrow + i + 1 >= this->grid_cols - 1)break;
		}
	}
	else if (sign == '-') {
		for (int i = 0; i < size + 1; i++) {
			if (centercol - i < 0 || centercol + i >= this->grid_cols) {
				berror = 1;
			}
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow][centercol - i] != -1) {
				cerror = 1;
			}
			if (centercol - i - 1 < 0)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow][centercol + i] != -1) {
				cerror = 1;
			}
			if (centercol + i + 1 >= this->grid_rows - 1)break;
		}
	}
	else if (sign == 'x') {
		for (int i = 0; i < size + 1; i++) {
			if (centerrow - i < 0 || centerrow + i >= this->grid_rows || centercol - i < 0 || centercol + i >= this->grid_cols) {
				berror = 1;
			}
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow - i][centercol - i] != -1){
				cerror = 1;
			}
			if (centerrow - i - 1 < 0 || centercol - i - 1 < 0)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow + i][centercol + i] != -1){
				cerror = 1;
			}
			if (centerrow + i + 1 >= this->grid_cols - 1 || centercol + i + 1 >= this->grid_rows - 1)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow - i][centercol + i] != -1){
				cerror = 1;
			}
			if (centerrow - i - 1 < 0 || centercol + i + 1 >= this->grid_rows - 1)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow + i][centercol - i] != -1){
				cerror = 1;
			}
			if (centerrow + i + 1 >= this->grid_cols - 1 || centercol - i - 1 < 0)break;
		}
	}
	else if (sign == '/') {
		for (int i = 0; i < size + 1; i++) {
			if (centerrow - i < 0 || centerrow + i >= this->grid_rows || centercol - i < 0 || centercol + i >= this->grid_cols) {
				berror = 1;
			}
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow - i][centercol + i] != -1){
				cerror = 1;
			}
			if (centerrow - i - 1 < 0 || centercol + i + 1 >= this->grid_rows - 1)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow + i][centercol - i] != -1){
				cerror = 1;
			}
			if (centerrow + i + 1 >= this->grid_cols - 1 || centercol - i - 1 < 0)break;
		}
	}

	if (berror) cout << "BORDER ERROR: Operator " << sign << " with size " << size << " can not be placed on (" << centerrow + 1<< "," << centercol + 1<< ").\n";
	if (cerror) cout << "CONFLICT ERROR: Operator " << sign << " with size " << size << " can not be placed on (" << centerrow + 1 << "," << centercol + 1<< ").\n";
	
	if (berror)return false;
	if (cerror)return false;

	//if everything is okay, place every element of the operator, take index of it in gridindex
	else {
		if (sign == '+') {
			for (int k = 0; k < size + 1; k++) {
				gridindex[centerrow - k][centercol] = num_operators;
				gridindex[centerrow + k][centercol] = num_operators;
				gridindex[centerrow][centercol - k] = num_operators;
				gridindex[centerrow][centercol + k] = num_operators;
				grid[centerrow - k][centercol] = '+';
				grid[centerrow + k][centercol] = '+';
				grid[centerrow][centercol - k] = '+';
				grid[centerrow][centercol + k] = '+';
			}
		}
		else if (sign == '-') {
			for (int k = 0; k < size + 1; k++) {
				gridindex[centerrow][centercol - k] = num_operators;
				gridindex[centerrow][centercol + k] = num_operators;
				grid[centerrow][centercol - k] = '-';
				grid[centerrow][centercol + k] = '-';
			}
		}
		else if (sign == 'x') {
			for (int k = 0; k < size + 1; k++) {
				gridindex[centerrow - k][centercol - k] = num_operators;
				gridindex[centerrow + k][centercol + k] = num_operators;
				gridindex[centerrow + k][centercol - k] = num_operators;
				gridindex[centerrow - k][centercol + k] = num_operators;
				grid[centerrow - k][centercol - k] = 'x';
				grid[centerrow + k][centercol + k] = 'x';
				grid[centerrow + k][centercol - k] = 'x';
				grid[centerrow - k][centercol + k] = 'x';
			}
		}
		else if (sign == '/') {
			for (int k = 0; k < size + 1; k++) {
				gridindex[centerrow + k][centercol - k] = num_operators;
				gridindex[centerrow - k][centercol + k] = num_operators;
				grid[centerrow + k][centercol - k] = '/';
				grid[centerrow - k][centercol + k] = '/';
			}
		}
	}

	cout << "SUCCESS: Operator " << sign << " with size " << size << " is placed on (" << centerrow + 1  << "," << centercol + 1<< ").\n";
	//add operator to the operator array
	this->operators[num_operators] = operatorOb;
	this->num_operators++;
	return true;
}

bool OperatorGrid::place(ArithmeticOperator * operatorOb) // this is basically as same as place_operator function without any print
{
	cerror = 0;
	berror = 0;
	int centerrow = operatorOb->get_x() - 1;
	int centercol = operatorOb->get_y() - 1;
	int size = operatorOb->get_size();
	char sign = operatorOb->get_sign();
	if (sign == '+') {
		for (int i = 0; i < size + 1; i++) {
			if (centerrow - i < 0 || centerrow + i >= this->grid_rows || centercol - i < 0 || centercol + i >= this->grid_cols) {
				berror = 1;
				return false;
			}
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow][centercol - i] != -1) {
				cerror = 1;
				return false;
			}
			if (centercol - i - 1 < 0)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow][centercol + i] != -1) {
				cerror = 1;
				return false;
			}
			if (centercol + i + 1 >= this->grid_rows - 1)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow - i][centercol] != -1) {
				cerror = 1;
				return false;
			}
			if (centerrow - i - 1 < 0)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow + i][centercol] != -1) {
				cerror = 1;
				return false;
			}
			if (centerrow + i + 1 >= this->grid_cols - 1)break;
		}
	}
	else if (sign == '-') {
		for (int i = 0; i < size + 1; i++) {
			if (centercol - i < 0 || centercol + i >= this->grid_cols) {
				berror = 1;
				return false;
			}
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow][centercol - i] != -1) {
				cerror = 1;
				return false;
			}
			if (centercol - i - 1 < 0)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow][centercol + i] != -1) {
				cerror = 1;
				return false;
			}
			if (centercol + i + 1 >= this->grid_rows - 1)break;
		}
	}
	else if (sign == 'x') {
		for (int i = 0; i < size + 1; i++) {
			if (centerrow - i < 0 || centerrow + i >= this->grid_rows || centercol - i < 0 || centercol + i >= this->grid_cols) {
				berror = 1;
				return false;
			}
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow - i][centercol - i] != -1) {
				cerror = 1;
				return false;
			}
			if (centerrow - i - 1 < 0 || centercol - i - 1 < 0)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow + i][centercol + i] != -1) {
				cerror = 1;
				return false;
			}
			if (centerrow + i + 1 >= this->grid_cols - 1 || centercol + i + 1 >= this->grid_rows - 1)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow - i][centercol + i] != -1) {
				cerror = 1;
				return false;
			}
			if (centerrow - i - 1 < 0 || centercol + i + 1 >= this->grid_rows - 1)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow + i][centercol - i] != -1) {
				cerror = 1;
				return false;
			}
			if (centerrow + i + 1 >= this->grid_cols - 1 || centercol - i - 1 < 0)break;
		}
	}
	else if (sign == '/') {
		for (int i = 0; i < size + 1; i++) {
			if (centerrow - i < 0 || centerrow + i >= this->grid_rows || centercol - i < 0 || centercol + i >= this->grid_cols) {
				berror = 1;
				return false;
			}
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow - i][centercol + i] != -1) {
				cerror = 1;
				return false;
			}
			if (centerrow - i - 1 < 0 || centercol + i + 1 >= this->grid_rows - 1)break;
		}
		for (int i = 0; i < size + 1; i++) {
			if (gridindex[centerrow + i][centercol - i] != -1) {
				cerror = 1;
				return false;
			}
			if (centerrow + i + 1 >= this->grid_cols - 1 || centercol - i - 1 < 0)break;
		}
	}

	if (sign == '+') {
		for (int k = 0; k < size + 1; k++) {
			gridindex[centerrow - k][centercol] = index;
			gridindex[centerrow + k][centercol] = index;
			gridindex[centerrow][centercol - k] = index;
			gridindex[centerrow][centercol + k] = index;
			grid[centerrow - k][centercol] = '+';
			grid[centerrow + k][centercol] = '+';
			grid[centerrow][centercol - k] = '+';
			grid[centerrow][centercol + k] = '+';
		}
	}
	else if (sign == '-') {
		for (int k = 0; k < size + 1; k++) {
			gridindex[centerrow][centercol - k] = index;
			gridindex[centerrow][centercol + k] = index;
			grid[centerrow][centercol - k] = '-';
			grid[centerrow][centercol + k] = '-';
		}
	}
	else if (sign == 'x') {
		for (int k = 0; k < size + 1; k++) {
			gridindex[centerrow - k][centercol - k] = index;
			gridindex[centerrow + k][centercol + k] = index;
			gridindex[centerrow + k][centercol - k] = index;
			gridindex[centerrow - k][centercol + k] = index;
			grid[centerrow - k][centercol - k] = 'x';
			grid[centerrow + k][centercol + k] = 'x';
			grid[centerrow + k][centercol - k] = 'x';
			grid[centerrow - k][centercol + k] = 'x';
		}
	}
	else if (sign == '/') {
		for (int k = 0; k < size + 1; k++) {
			gridindex[centerrow + k][centercol - k] = index;
			gridindex[centerrow - k][centercol + k] = index;
			grid[centerrow + k][centercol - k] = '/';
			grid[centerrow - k][centercol + k] = '/';
		}
	}
	cerror = 0;
	berror = 0;
	
	this->operators[index] = operatorOb;
	return true;
}

bool OperatorGrid::move_operator(int x, int y, char direction, int move_by) {
	bool success;
	//get index from gridindex
	index = gridindex[x - 1][y - 1];
	//get operator from array using that index
	ArithmeticOperator* operatorOb = this->operators[index];

	int centerrow = operatorOb->get_x() - 1;
	int centercol = operatorOb->get_y() - 1;
	int size = operatorOb->get_size();
	char sign = operatorOb->get_sign();
	//initial values will be necessity if there will be any problem
	int temprow = centerrow, tempcol = centercol, tempsize = size;

	if (direction == 'U' || direction == 'u')centerrow = centerrow - move_by;
	else if (direction == 'D' || direction == 'd')centerrow = centerrow + move_by;
	else if (direction == 'R' || direction == 'r')centercol = centercol + move_by;
	else if (direction == 'L' || direction == 'l')centercol = centercol - move_by;

	for (int i = 0; i < this->grid_rows; i++) {
		for (int j = 0; j < this->grid_cols; j++) {
			if (gridindex[i][j] == index) {
				gridindex[i][j] = -1;
				grid[i][j] = '0';
			}
		}
	}

	centerrow++;
	centercol++;
	//reset values and try to place it to the new coordinates
	operatorOb->reset(centerrow, centercol, size);
	success = place(operatorOb);
	if (success) {
		cout << "SUCCESS: " << sign << " moved from (" << temprow + 1 << "," << tempcol + 1 << ") to (" << centerrow << "," << centercol << ").\n";
		return true;
	}
	else {
		//if there is any error go back to initial values
		if (berror)cout << "BORDER ERROR: " << sign << " can not be moved from (" << temprow + 1 << "," << tempcol + 1 << ") to (" << centerrow << "," << centercol << ").\n";
		if (cerror)cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << temprow + 1 << "," << tempcol + 1 << ") to (" << centerrow << "," << centercol << ").\n";
		centerrow = temprow + 1;
		centercol = tempcol + 1;
		size = tempsize;
		operatorOb->reset(centerrow, centercol, size);
		//place it to its initial place
		place(operatorOb);
		return false;
	}
}

void OperatorGrid::print_operators() {

	for (int i = 0; i < this->num_operators; i++) {
		operators[i]->print_operator();
	}
}

OperatorGrid::~OperatorGrid()
{

	cout << "DESTRUCTOR: GIVE BACK[" << grid_rows << "," << grid_cols << "] chars." << endl;
	cout << "DESTRUCTOR: GIVE BACK[" << num_operators << "] Operators." << endl;

	for (int i = 0; i < grid_rows; i++) {
		delete[] grid[i];
		delete[] gridindex[i];
	}
	delete[] grid;
	delete[] gridindex;
}


// Oytun Demirbilek
// 150150032
#ifndef OPERATORGRID_H
#define OPERATORGRID_H
#define MAX_OPERATOR_SIZE 9
#include "ArithmeticOperator.h"

class OperatorGrid
{
	int grid_rows;
	int grid_cols;
	int index;
	char **grid;
	int **gridindex; // to identify operators individually
	int num_operators;
	int berror, cerror; // checking errors
	ArithmeticOperator *operators[MAX_OPERATOR_SIZE];
public:
	OperatorGrid(int rows, int cols);
	~OperatorGrid();

	bool place_operator(ArithmeticOperator *);
	bool place(ArithmeticOperator *); // to try to place an operator, check if it is okay or not
	bool move_operator(int x, int y, char direction, int move_by);
	void print_operators();
};

#endif

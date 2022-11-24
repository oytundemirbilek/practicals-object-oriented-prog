// Oytun Demirbilek
// 150150032
#ifndef OPERATOR_H
#define OPERATOR_H

class Operator
{
	int center_x;
	int center_y;
	int op_size;

public:
	Operator();
	Operator(int x, int y, int size);
	void reset(int new_x, int new_y, int new_size);

	void set_x(int new_x);
	void set_y(int new_y);
	void set_size(int new_size);

	int get_x();
	int get_y();
	int get_size();

	~Operator();
};

#endif
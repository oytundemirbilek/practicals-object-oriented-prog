// Oytun Demirbilek
// 150150032
#include "pch.h"
#include "Operator.h"

Operator::Operator() {

}
Operator::Operator(int x, int y, int size)
{
	this->center_x = x;
	this->center_y = y;
	this->op_size = size;
}	
void Operator::reset(int new_x, int new_y, int new_size) {
	this->center_x = new_x;
	this->center_y = new_y;
	this->op_size = new_size;
}

void Operator::set_x(int new_x) {
	this->center_x = new_x;
}
void Operator::set_y(int new_y) {
	this->center_y = new_y;
}
void Operator::set_size(int new_size) {
	this->op_size = new_size;
}

int Operator::get_x() {
	return this->center_x;
}
int Operator::get_y() {
	return this->center_y;
}
int Operator::get_size() {
	return this->op_size;
}

Operator::~Operator()
{
}

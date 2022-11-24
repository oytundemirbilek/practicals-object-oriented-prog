//Oytun Demirbilek
//150150032

#ifndef DISH_H
#define DISH_H
#include "StockMaterial.h"
#include <iostream>
using namespace std;

class Dish
{
private:
	char* dishname;
	int ingcount;
	StockMaterial* ingredients;
public:
	Dish();
	void setFeatures(char* name, StockMaterial* materials, int count);
	double getCost();
	char * getName();
	int cookDish(int dishcount, int stock, StockMaterial* stored);
	void print();
	~Dish();
};
#endif

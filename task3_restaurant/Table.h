//Oytun Demirbilek
//150150032

#ifndef TABLE_H
#define TABLE_H

#include "StockMaterial.h"
#include "Dish.h"

#include <iostream>
using namespace std;

class Table
{
private:
	int orderCount;
	int *dishCounts; // array of numbers to keep number of each order
	Dish * orders;

public:
	Table();
	void setOrders(int count, int* dishc, Dish * name);
	void checkout(int stock, StockMaterial*stored);
	~Table();
};
#endif

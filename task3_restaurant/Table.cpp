//Oytun Demirbilek
//150150032
#include "pch.h"
#include "Table.h"
#include "StockMaterial.h"
#include "Dish.h"

#include <iostream>
using namespace std;

Table::Table()
{
	
}


void Table::checkout(int stock, StockMaterial*stored) {
	
	double total = 0;
	int success = 0;
	for (int i = 0; i < orderCount; i++) {
		success = orders[i].cookDish(dishCounts[i], stock, stored);
		if (success) {
			cout << dishCounts[i] << " " << orders[i].getName() << " cost: " << orders[i].getCost() * dishCounts[i] << endl;
			total = total + orders[i].getCost() * dishCounts[i];
		}
		else {
			cout << "We don't have enough " << orders[i].getName() << endl;
		}
	}

	cout << "Tip is " << total * 15 / 100 << endl;
	cout << "Total cost: " << (total * 8 / 100) + (total * 15 / 100) + total << " TL" << endl;
	cout << "**************************" << endl;
}

void Table::setOrders(int orderc, int* dishc, Dish* newdish) {
	
	orderCount = orderc;
	orders = new Dish[orderc];
	dishCounts = new int[orderc];
	for (int i = 0; i < orderc; i++) {
		orders[i] = newdish[i];
		dishCounts[i] = dishc[i];
	}
}

Table::~Table()
{
	cout << "Table Destructor" << endl;
}

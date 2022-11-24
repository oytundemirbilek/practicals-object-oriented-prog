//Oytun Demirbilek
//150150032
#include "pch.h"
#include "Dish.h"
#include "StockMaterial.h"

#include <string.h>
#include <iostream>
using namespace std;

Dish::Dish() {
}

void Dish::setFeatures(char* name, StockMaterial* materials, int count)
{
	int length = strlen(name);
	dishname = new char[length];
	strcpy(dishname, name);
	ingcount = count;
	ingredients = new StockMaterial[count];
	for (int i = 0; i < count; i++) {
		ingredients[i] = materials[i];
	}
}

double Dish::getCost() {
	double cost = 0;
	for (int i = 0; i < ingcount; i++) {
		cost = cost + ingredients[i].getCost();
	}
	return cost;
}

int Dish::cookDish(int dishcount, int stocksize, StockMaterial* storage) {
	int success = 1;
	for (int i = 0; i < ingcount; i++) {
		for (int j = 0; j < stocksize; j++) {
			if (strcmp(ingredients[i].getName(), storage[j].getName()) == 0) {
				success = success * storage[j].setAmount(dishcount * ingredients[i].getAmount());
			}
		}
	}
	// calculate if a dish is possible to cook or not
	return success;
}

char* Dish::getName() {
	return dishname;
}

Dish::~Dish()
{
	cout << "Dish Destructor" << endl;
}

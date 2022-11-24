//Oytun Demirbilek
//150150032
#include "pch.h"
#include "StockMaterial.h"
#include <string.h>
#include <iostream>
using namespace std;
StockMaterial::StockMaterial()
{
}

void StockMaterial::print() {
	cout << stockname << " " << totalamount << " " << price << endl;
}

void StockMaterial::setFeatures(char* name, double itemamount, double priceperunit) {
	totalamount = itemamount;
	price = priceperunit;
	strcpy(stockname, name);
}

double StockMaterial::getCost() {
	return totalamount * price;
}

double StockMaterial::getPrice() {
	return price;
}

double StockMaterial::getAmount() {
	return totalamount;
}

int StockMaterial::setAmount(double amount) {
	if (totalamount >= amount) {
		totalamount = totalamount - amount;
		return 1;
	}
	// assigning new amount to update stored food and drinks
	return 0;
	
}

char* StockMaterial::getName() {
	return stockname;
}

StockMaterial::~StockMaterial()
{
	cout << "Stock Destructor" << endl;
}

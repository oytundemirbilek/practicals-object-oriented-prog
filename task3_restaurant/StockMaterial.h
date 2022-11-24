//Oytun Demirbilek
//150150032

#ifndef STOCKMATERIAL_H
#define STOCKMATERIAL_H
#include <iostream>
using namespace std;
class StockMaterial
{
public:
	StockMaterial();

	void print();
	void setFeatures(char* name, double itemamount, double priceperunit);
	double getCost();
	double getAmount();
	int setAmount(double amount);
	char* getName();
	double getPrice();
	~StockMaterial();
private:

	double totalamount;
	double price;
	char stockname[25];
};
#endif
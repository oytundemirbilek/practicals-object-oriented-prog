#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"

#include <iostream>
using namespace std;

class Restaurant
{
private:
	Table tables[5];
public:
	Restaurant();
	~Restaurant();
};
#endif

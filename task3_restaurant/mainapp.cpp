//Oytun Demirbilek
//150150032

#include <cstdio>
#include "StockMaterial.h"
#include "Dish.h"
#include "Table.h"

#include <iostream>
#include <cstdlib>

#include <cstring>
using namespace std;

int main()
{
	double type, itemamount, price;
	char name[25], line[500], dishname[25], c = '0';

	// c and counter defined as temporary variables to be used in file handling
	int stocksize = 0, counter = 0;

	FILE * fpstock = fopen("stock.txt", "r");
	FILE * fpmenu = fopen("menu.txt", "r");
	FILE * fporder = fopen("order.txt", "r");

	fgets(line, 500, fpstock);

	// FINDING STOCK SIZE
	while (!feof(fpstock)) {
		fgets(line, 500, fpstock);
		stocksize++;
	}

	rewind(fpstock);
	fgets(line, 500, fpstock);

	StockMaterial * stock = new StockMaterial[stocksize];
	int j = 0;

	// CREATING STOCK AS ARRAY OF STOCK MATERIAL OBJECTS
	for (int i = 0; i < stocksize; i++) {
		j = 0;
		c = fgetc(fpstock);
		while (c != '\t') {
			name[j] = c;
			c = fgetc(fpstock);
			j++;
		}
		name[j] = '\0';
		fscanf(fpstock, "%lf", &type);
		fscanf(fpstock, "%lf", &itemamount);
		fscanf(fpstock, "%lf\n", &price);
		stock[i].setFeatures(name, itemamount, price);
		
	}

	fgets(line, 500, fpmenu);
	int menusize = 0;

	// FINDING MENU SIZE
	while (!feof(fpmenu)) {
		fgets(line, 500, fpmenu);
		menusize++;
	}

	rewind(fpmenu);
	fgets(line, 500, fpmenu);

	Dish * menu = new Dish[menusize];
	int * n_ing = new int[menusize];
	StockMaterial * ingredients = new StockMaterial;

	// FINDING NUMBER OF INGREDIENTS FOR EACH MENU OBJECT
	for (int i = 0; i < menusize; i++) {
		c = fgetc(fpmenu);
		while (c != '\t')c = fgetc(fpmenu);
		while (c != '\n' && !feof(fpmenu)) {
			c = fgetc(fpmenu);
			if (c == ',')counter++;
		}
		n_ing[i] = counter + 1;
		counter = 0;
	}

	rewind(fpmenu);
	fgets(line, 500, fpmenu);

	int ingcount;
	
	// CREATING MENU AS ARRAY OF DISH OBJECTS
	for (int i = 0; i < menusize; i++) {
		ingcount = n_ing[i];
		ingredients = new StockMaterial[ingcount];

		j = 0;
		c = fgetc(fpmenu);
		while (c != '\t') {
			dishname[j] = c;
			c = fgetc(fpmenu);
			j++;
		}
		dishname[j] = '\0';
		for (int k = 0; k < ingcount; k++) {
			c = fgetc(fpmenu);
			if (c == 'N') {
				fgetc(fpmenu);
				fgetc(fpmenu);
				fgetc(fpmenu);
				for (int n = 0; n < stocksize; n++) {
					if (strcmp(stock[n].getName(), dishname) == 0) {
						price = stock[n].getPrice();
					}
				}
				ingredients[k].setFeatures(dishname, 1, price);
			}
			else {
				j = 0;
				while (c != ' ') {
					name[j] = c;
					c = fgetc(fpmenu);
					j++;
				}
				name[j] = '\0';
				itemamount = atof(name);

				j = 0;
				c = fgetc(fpmenu);
				while (c != ' ' && c != ',' && c != '\n') {
					name[j] = c;
					c = fgetc(fpmenu);
					j++;
				}
				name[j] = '\0';
				if (c != ',') {
					if (strcmp(name, "ml") == 0 || strcmp(name, "gram") == 0) {
						j = 0;
						c = fgetc(fpmenu);
						while (c != ',' && c != '\n') {
							name[j] = c;
							c = fgetc(fpmenu);
							j++;
						}
						if(c == ',')fgetc(fpmenu);
						name[j] = '\0';
					}
					else {
						while (c != ',' && c != '\n') {
							name[j] = c;
							c = fgetc(fpmenu);
							j++;
						}
						fgetc(fpmenu);
						name[j] = '\0';
					}
				}
				else {
					fgetc(fpmenu);
				}
				for (int n = 0; n < stocksize; n++) {
					if (strcmp(stock[n].getName(), name) == 0) {
						price = stock[n].getPrice();
					}
				}
				ingredients[k].setFeatures(name, itemamount, price);
				
			}
		}

		menu[i].setFeatures(dishname, ingredients, ingcount);
	}

	Table * tables = new Table[5];
	Dish * orders = new Dish;

	j = 0;
	int k;
	c = '0';
	int num_ord, * num_dish;

	// CREATING ARRAY OF TABLES WITH TABLE OBJECT
	while (!feof(fporder)) {

		fgets(line, 500, fporder);
		fscanf(fporder, "%d ", &num_ord);

		orders = new Dish[num_ord];
		num_dish = new int[num_ord];

		for (int i = 0; i < num_ord; i++) {
			fscanf(fporder, "%d ", &num_dish[i]);
			k = 0;
			c = fgetc(fporder);
			while (c != '\n' && !feof(fporder)) {
				name[k] = c;
				c = fgetc(fporder);
				k++;
			}
			name[k] = '\0';
			
			for (int n = 0; n < menusize; n++) {
				if (strcmp(menu[n].getName(), name) == 0) {
					orders[i] = menu[n];
				}
			}
		}
		tables[j].setOrders(num_ord, num_dish, orders);
		j++;
	}

	for (int i = 0; i < j; i++) {
		cout << "Table" << i + 1 << " ordered:" << endl;
		tables[i].checkout(stocksize, stock);
	}

	fclose(fpstock);
	fclose(fpmenu);
	fclose(fporder);

	return 0;
}

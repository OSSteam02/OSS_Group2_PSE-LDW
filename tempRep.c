#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "tempRep.h"
#define MAX 100


int main(void) {
	std std_arr[MAX];
	rep rep_arr[MAX];
	std temp_t;
	rep temp_p;

	int select = 0;

	while(1) {

		select = selectMenu();

		if(select == 0) break; //end
		else if(select == 1) { //read
			createProduct(temp_p); //add product
		}
		else if (select == 2) {
			readProduct(temp); //show product
		}
		else if (select == 3) {
			updateProduct(temp_p); //update product
		}
		else if (select == 4) {
			deleteProduct(temp_p); //delete product
		}
		else if (select == 5) {
			char name[20];
			gets(name);

			findName(temp_p, name); // find by name
		}
		else if (select == 6) {
			int price;
			scanf("%d", &price);

			findPrice(temp_p, price); // find by price
		}
		else if (select == 7) {
			int dev;
			scanf("%d", &dev);

			findDeliv(temp_p, dev); // find by del
		}
		else if (select == 8) {
			//readFile(file); //load file
		}
		else if (select == 9) {
			//saveFile(file); //save file
		}
	}

	return 0;
}

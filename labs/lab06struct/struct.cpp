/**
* Author:		Youngsup Kim
* Description:	This program is written to learn the following subjects:
*		1. structure - struct
*		2. array of structure
*		3. typedef struct in C, "using new_type = old_type" in C++
*		4. new/delete, rand()
*		5. pointer, pointer arithmetic in a for loop, pass by reference
*		6. passing and using a pointer as a function return value
*		7. no magic numbers
*
* On my honour, I pledge that I have neither received nor provided improper
* assistance in the completion of this assignment.
* Signed: Jeon Yeo Hun YOUR NAME Jeon Yeo Hun  Section:03  Student Number: 21500630
*
* History:
* 2019/02/12:		Created in C++
*/

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cassert>
#include <ctime>
#include <algorithm>


#include "nowic.h"
using namespace std;

#define MAX_SPEED 200
#define NCARS 3

struct Car {
	string model;
	double speed;
};
using pCar = Car*;

// Randomly get a model, Use call-by-pointer
void set_model(string *model) {
	DPRINT(cout << ">>set_model\n";);
	string models[] = {"Bentley", "Corvette", "Maserti", "Porsche",
						"Saleen", "StingRay", "Genesis"};
	int size = sizeof(models)/sizeof(models[0]);

	int choice = rand() % size;
	DPRINT(cout << "choice=" << choice << " model=" << models[choice] << endl;);
	*model = models[choice];
	DPRINT(cout << " model=" << *model << endl;);
}

// Set to a speed randomly in the range [1..MAX_AGE] inclusively.
// Use call-by-pointer
void set_speed(double *speed) {
	*speed = rand() % (MAX_SPEED + 1);
	DPRINT(cout << ">>set_speed: " << *speed << endl;);
}

void print_cars(pCar list, int nCars) {
	DPRINT(cout << "print_cars: nCars=" << nCars << endl;);
	for (int i = 0; i < nCars; i++, list++) {
		cout << "\t(" << i + 1 << ")" << list->model << "\t" << list->speed << endl;
	}
}

// Step 1
// Test a program which uses "struct car and NCARS"
// Ask the user to enter a model and its speed.
// Use a magic number NCARS and struct car array of structure.
void step1() {
	DPRINT(cout << "Step 1: NCARS=" << NCARS << endl;);

	Car arr[NCARS];

	for (int i = 0; i < NCARS; i++) {
		// To set model and speed,
		// use GetString() and GetDouble() in libnowic.a or nowic.lib
		cout << "[" << i + 1 << "/" << NCARS << "]\n";
		arr[i].model = GetString("Enter a model: ");
		arr[i].speed = GetDouble("Enter a speed: ");

	}

	// use for loop to print the car list
	for (int i=0 ; i< NCARS ; i++){
		cout << "\t(" << i+1 << ") " << arr[i].model << "\t" <<arr[i].speed << endl;
	}
}

// Step 2
// Allocate a pointer to an array structure instead of using a fixed
// size array. Don't use NCARS, but use nCars which user entered.
// Use the array notation [] to access members
void step2(const int nCars) {
	DPRINT(cout << "Step 2: nCars=" << nCars << endl;);

	Car *arr = new (nothrow) Car[nCars];
	assert(arr!=nullptr);

	for (int i = 0; i < nCars; i++) {
		cout << "[" << i + 1 << "/" << nCars << "]\n";
		arr[i].model = GetString("Enter a model: ");
		arr[i].speed = GetDouble("Enter a speed: ");
	}

	// use for loop to print the car list. don't use print_cars().
	for (int i=0 ; i< nCars ; i++){
		cout << "\t(" << i+1 << ") " << arr[i].model << "\t" <<arr[i].speed << endl;
	}

	// deallocate
	delete [] arr;
}

// Step 3:
// Don't use the array notation [], but use -> to access members
void step3(const int nCars) {
	DPRINT(cout << "Step 3: nCars=" << nCars << endl;);
	// use new to allocate an array structure to a pointer

	Car *arr = new (nothrow) Car[nCars];
	assert(arr!=nullptr);

	// get a copy of the pointer list; save the original pointer to use later.
	Car * optr = arr;

	// use for loop to print the car list. don't use print_cars().
	for (int i = 0; i < nCars; i++) {
		cout << "[" << i + 1 << "/" << nCars << "]\n";
		(arr+i)->model = GetString("Enter a model: ");
		(arr+i)->speed = GetDouble("Enter a speed: ");
	}
	// recover the original pointer to print the list from the first
	for (int i=0 ; i< nCars ; i++){
		cout << "\t(" << i+1 << ") " << (arr+i)->model << "\t" <<(arr+i)->speed << endl;
	}

	delete [] arr;
}

// Step 4:
// set models and speeds randomly
// Use "using pCar = car*" instead of typedef
// Implement a function called print_cars() which takes two arguments
// as shown below:
//     print_cars(pCar list, int nCars)
// Implement functions, set_model() and set_speed(),
// which radomly set both model and speed.
void step4(const int nCars) {
	DPRINT(cout << "Step 4: nCars=" << nCars << endl;);

	pCar arr =  new (nothrow) Car [nCars];

	for (int i=0 ; i< nCars ; i++){
		set_model(&((arr+i)->model));
		set_speed(&((arr+i)->speed));
		cout << "\t(" << i+1 << ") " << (arr+i)->model << "\t" <<(arr+i)->speed << endl;
	}

	delete [] arr;
}

// Step 5:
// Copy step4() and rename it as step5()
// Make this function return type as the pointer of the cars list.
// Remove the code which print the list and return the pointer to main()
pCar step5(const int nCars) {
	DPRINT(cout << "Step 5: nCars=" << nCars << endl;);

	pCar arr =  new (nothrow) Car [nCars];

	for (int i=0 ; i< nCars ; i++){
		set_model(&((arr+i)->model));
		set_speed(&((arr+i)->speed));
	}
	return arr;
}


// Step 6:
// Copy step4() and rename it as step6() below these comments.
// - Copy set_model() and set_speed() as they are and place
//   below these comments, but above step6() function.
// - change the model names into all capital letters
// - change the parameter such that each one uses call-by-reference.
//
// There are multiple function definitions but with different signatures.
// This technology is called a function overloading available in C++.
// Randomly get a model and a speed, use call-by-reference.
// Now do the same thing as Step 4~5 except using call-by-reference.

// your code here for set_model()
// your code here for set_speed()
void set_model(string & model) {
	DPRINT(cout << ">>set_model\n";);
	string models[] = {"BENTLEY", "CORVETTE", "MASERATI", "PORSCHE",
						"SALEEN", "STRINGRAY", "GENESIS"};
	int size = sizeof(models)/sizeof(models[0]);

	int choice = rand() % size;
	DPRINT(cout << "choice=" << choice << " model=" << models[choice] << endl;);
	model = models[choice];
	DPRINT(cout << " model=" << *model << endl;);
}

// Set to a speed randomly in the range [1..MAX_AGE] inclusively.
// Use call-by-pointer
void set_speed(double & speed) {
	speed = rand() % (MAX_SPEED + 1);
	DPRINT(cout << ">>set_speed: " << *speed << endl;);
}


// Set to a speed randomly in the range [1..MAX_AGE] inclusively.
// Use call-by-pointer

void step6(int nCars) {
	DPRINT(cout << "Step 6: nCars=" << nCars << endl;);

	pCar arr =  new (nothrow) Car [nCars];
	// Use call-by-reference.

	for (int i=0 ; i< nCars ; i++){
		set_model((arr+i)->model);
		set_speed((arr+i)->speed);
		cout << "\t(" << i+1 << ") " << (arr+i)->model << "\t" <<(arr+i)->speed << endl;
	}

	delete [] arr;
}

int main(int argc, char *argv[]) {
	int option;
	int nCars;
	pCar list;
	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		cout << "\n\tTesting Options\n"
			"\t1 - step 1: Using a fixed sized array of structure\n"
			"\t2 - step 2  Using `new` and an array notation\n"
			"\t3 - step 3: Using `new` and a pointer notation\n"
			"\t4 - step 4: Using `pCar`, print_cars(), set_model(), set_speed()\n"
			"\t5 - step 5: Printing car list in main()\n"
			"\t6 - step 6: Using call-by-reference, set_model(), set_speed()\n"
			"\t7 - step 7: Find and fix a memory leak.\n";

		option = GetInt("\tEnter an option(0 to quit): ");
		if (option >= 2 && option <= 6) {
			nCars = GetInt("\tEnter a number of cars: ");
			if (nCars == 0) continue;
		}
		switch (option) {
		case 1:
			step1();
			break;
		case 2:
			step2(nCars);
			break;

		case 3:
			step3(nCars);
			break;

		case 4:
			step4(nCars);
			break;

		case 5:
			// invoke step5() and get the pointer returned to print here.
			list = step5(nCars);

			// use print_cars() to print the list.
			print_cars(list, nCars);

			delete [] list;
			break;

		case 6:
			step6(nCars);
			break;

		default:
			break;
		}
	} while (option != 0);

	cout << "Happy Coding~\n";
	// system("pause");
	return EXIT_SUCCESS;
}

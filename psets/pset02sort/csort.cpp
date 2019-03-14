/*
	On my Honour, I pledge that I have neither recieved nor provided improper assistance in the completion of this assignment.
	Signed: Jeon Yeo Hun
	Section: 03
	Student Number: 21500630
*/

#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "nowic.h"
using namespace std;

void sort(int[], int);
#if 1
int main(void) {
	int i, n;
	srand(time(NULL));
	cout << "Enter the number of samples: ";
	cin >> n;

	if (n < 1 ) {
		cout << "invalid number\n";
		exit(1);
	}

	int* list = new int[n];


	cout << "\nUnSorted array:\n";
	for (i = 0; i < n; i++) {       // randomly generate numbers
		list[i] = rand() % 1000;
		cout << list[i] << "\t";
	}

	sort(list, n);

	cout << "\nSorted array:\n";
	for (i = 0; i < n; i++) {
		cout << list[i] << "\t";
	}
	printf("\n");

	return 0;
}
#endif

void sort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min]){
				min = j;
			}
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
	}
}

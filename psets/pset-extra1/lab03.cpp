// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
/*
* This brute force version of Selection Sort that takes O(n^2).
*
*  Lab - Using C++, rewrite lab02a.cpp and name the file as lab03.cpp.
*		- <iostream>, <cstdlib>, <cmath>, <cassert>
*		- using namespace std
*		- cin, cout, endl
*		- use new and delete operators instead of malloc() and free()
*/
#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "nowic.h"
#include "sort.h"
using namespace std;



void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

#if 1
int main() {
	int N = 0;
	string name[4] = {"BUBBLE", "INSERT", "QUICK", "SELECT"};
	clock_t start, end;
	N = GetInt();
	void (*fp[]) (int*, int, int(*comp)(int, int)) = {bubbleSort, insertionSort, quickSort, selectionSort};

	// int *list = (int *)malloc(N * sizeof(int));
	int *list = new int[N];
	assert(list != NULL);

	for (int i = 0; i < N; i++)
		list[i] = rand() % N;

	// default sorting
	cout << "\nTest Case: Not passing a default argument: quickSort(list, N)\n" << "=============================================================" << endl;

	cout << "NOTsorted: ";
	print_list(list, N);

	selectionSort(list, N, ascending);
	cout << "sorted: ";
	print_list(list, N);

	// ascending ordered sorting
	cout << "\nTest Case: Not passing a default argument: quickSort(list, N, up)\n" << "=============================================================" << endl;

	cout << "NOTsorted: ";
	print_list(list, N);

	selectionSort(list, N, ascending);
	cout << "sorted: ";
	print_list(list, N);

	// descending ordered sorting
	cout << "\nTest Case: Not passing a default argument: quickSort(list, N, dn)\n" << "=============================================================" << endl;

	cout << "NOTsorted: ";
	print_list(list, N);

	selectionSort(list, N, descending);

	cout << "sorted: ";
	print_list(list, N);


	cout << "\nTest Case: Using an array of function pointers\n" << "=============================================================" << endl;

	for(int i=0 ; i<4 ; i++){
		for (int i = 0; i < N; i++) {list[i] = rand() % N;}
		cout << "Notsorted[" << name[i] <<"]: ";
		print_list(list, N);
		cout << "Up sorted[" << name[i] <<"]: ";
		start = clock();
		fp[i](list, N, ascending);
		end = clock();
		cout << "\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
		print_list(list, N);

		cout << "Dn sorted[" << name[i] <<"]: ";
		start = clock();
		fp[i](list, N, descending);
		end = clock();
		cout << "\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
		print_list(list, N);
		cout << "\n";
	}

	delete[] list;
	cout << "Happy Coding~~\n";
}
#endif

/*
	On my Honour, I pledge that I have neither recieved nor provided improper assistance in the completion of this assignment.
	Signed: Jeon Yeo Hun
	Section: 03
	Student Number: 21500630
*/
#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include <ctype.h>
#include <stdlib.h>
#include "nowic.h"
#include "sort.h"
using namespace std;

int isStringInt(string str){
		return atoi(str.c_str());
}

void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

#if 1
int main(int argc, char* argv[]) {
	int N = 0;
	string name[4] = {"BUBBLE", "INSERT", "QUICK", "SELECT"};
	clock_t start, end;

	if (argc == 1){
		cout << "Enter a number of samples: ";
		cin >> N;
	}
	else{
		N = isStringInt(argv[1]);
	}

	if (N==0 || N<0){
		cout << "Your input (" << N << ") cannot be proccessed" << endl;
		cout << "Usage: sort[N]" << endl;
		exit(1);
	}


	void (*fp[]) (int*, int, int(*comp)(int, int)) = {bubbleSort, insertionSort, quickSort, selectionSort};

	// int *list = (int *)malloc(N * sizeof(int));
	int *list = new (nothrow) int[N]; // nothrow 를 사용하면 allocation이 안됐을 때, 예외처리를 해준다. 잘못되면 nullptr을 리턴해준다.
	assert(list != nullptr);	// list에 nullptr이 저장되어 있으면 프로그램을 종료시킨다.

	for (int i = 0; i < N; i++)
		list[i] = rand() % N;

	// default sorting
	cout << "\nTest Case: Not passing a default argument: quickSort(list, N)\n" << "=============================================================" << endl;

	cout << "NOTsorted: ";
	print_list(list, N);

	quickSort(list, N);
	cout << "sorted: ";
	print_list(list, N);

	// ascending ordered sorting
	cout << "\nTest Case: Not passing a default argument: quickSort(list, N, up)\n" << "=============================================================" << endl;

	cout << "NOTsorted: ";
	print_list(list, N);

	quickSort(list, N, ascending);
	cout << "sorted: ";
	print_list(list, N);

	// descending ordered sorting
	cout << "\nTest Case: Not passing a default argument: quickSort(list, N, dn)\n" << "=============================================================" << endl;

	cout << "NOTsorted: ";
	print_list(list, N);

	quickSort(list, N, descending);

	cout << "sorted: ";
	print_list(list, N);


	cout << "\nTest Case: Using an array of function pointers\n" << "=============================================================" << endl;

	for(int i=0 ; i<sizeof(fp)/sizeof(fp[0]) ; i++){
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

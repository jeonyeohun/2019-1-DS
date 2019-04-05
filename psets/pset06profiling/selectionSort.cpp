/*
	On my Honour, I pledge that I have neither recieved nor provided improper assistance in the completion of this assignment.
	Signed: Jeon Yeo Hun
	Section: 03
	Student Number: 21500630
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

void selectionSort(int *list, int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		// Swap min found with the first one of unsorted
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

#if 0
int main() {
	/*
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	const int N = sizeof(list) / sizeof(list[0]);
	*/

	// 사용자에게 샘플 숫자를 받아서 메모리 할당하기 //
	int N;
	cout << "Enter a number of samples to sort: ";
	cin >> N;

	// int *list = (int *)malloc(N * sizeof(int));
	int *list = new int[N];
	assert(list != NULL);

	for (int i = 0; i < N; i++)
		list[i] = rand() % N;

	cout << "UNSORTED: " << endl;
	print_list(list, N);

	selectionSort(list, N);

	cout << "SORTED: " << endl;
	print_list(list, N);

	delete[] list;
	cout << "Happy Coding~~\n";
}
#endif

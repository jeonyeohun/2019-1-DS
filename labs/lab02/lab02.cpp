// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
/*
* lab02.cpp  & lab02a.cpp
* This brute force version of Selection Sort that takes O(n^2).
*
* Compilation:
*   g++ lab02.cpp -o lab02
*   g++ lab02a.cpp -o lab02a
*
* Lab: (1) Improve the following code in C first. Name the file as lab02a.cpp
*      (2) Then recode it in C++. Name the file as lab02b.cpp
*
*	1. Understand the following C code.
*   - #if
*		- const
*		- rand()
*		- % operator
*  2. Use dynamic allocation for the array
*		- Add assert after malloc()
*		- Add free()
*  3. NMN principle - no magic number
*     DRY principle - don't repeat yourself
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printlist (int *list, int N); // prototype 정의
void selectionSort(int *list, int n) { // selectionsort 알고리즘
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

// 나중에 알고리즘을 합쳐서 하나의 파일로 만들 때, 메인함수가 여러개 있기 때문에 오류가 발생. #if 0으로 두면 컴파일할 때 메인을 빼고 컴파일을 해준다.
// 알고리즘이 제대로 작동하는지 테스트 하기 위해 #if 1 ~ #endif 로 묶어주는 것.
#if 1
int main() {
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 10, -1 };
	const int N = sizeof(list)/sizeof(list[0]);	// 배열 사이즈를 계산해서 자동으로 상수를 정의함.

	printf("UNSORTED: \n");
  printlist(list, N);
	selectionSort(list, N);
	printf("SORTED: \n");
  printlist(list, N);

	// system("pause");
  printf("Happy Coding~~\n");
}
#endif

void printlist (int *list, int N){
	for (int i = 0; i < N; i++)
    printf("%d ", list[i]);
  printf("\n");
}

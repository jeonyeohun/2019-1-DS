/** File: heapsort.cpp */

/*
 Include the following line at the top of your every file with your name signed.
 On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: Jeon, Yeo Hun
 *
 
 
/* This implements the heap sort algorithm (in-place).
* A given arbitrary input array goes through two passes.
* 1st pass: heap construction (heapify)
* 2nd pass: successively remove the root(max) and
*           add it to the end of array
* The follwing outputs show how the algorithm flows.
NOTE: This implementation does not sort the first element in the array.
NOTE: N=?? k=? .... lines are outputs at the end of each sink()
Unsorted:a[]: S O R T E X A M P L E
   N=11  k=5: S O R T L X A M P E E
   N=11  k=4: S O R T L X A M P E E
   N=11  k=3: S O X T L R A M P E E
   N=11  k=2: S T X P L R A M O E E
   N=11  k=1: X T S P L R A M O E E
Heap ordered: X T S P L R A M O E E
   N=10  k=1: T P S O L R A M E E
   N= 9  k=1: S P R O L E A M E
   N= 8  k=1: R P E O L E A M
   N= 7  k=1: P O E M L E A
   N= 6  k=1: O M E A L E
   N= 5  k=1: M L E A E
   N= 4  k=1: L E E A
   N= 3  k=1: E A E
   N= 2  k=1: E A
   N= 1  k=1: A
  Sorted:a[]: A E E L M O P R S T X
*
* Author: Youngsup Kim, idebtor@gmail.com
* 2014/04/30	YSK	Creation
* 2019/05/15	C++ conversion
*/

#include <iostream>
using namespace std;
typedef char Key;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// define a function pointer that accepts a key array, int, int as arguments
bool (*comp)(Key*, int, int);

//////////// helper functions to restore the PQ invariant ///////////
bool less(Key* a, int i, int j) {
	return a[i] < a[j];
}
bool more(Key* a, int i, int j) {
	return a[i] > a[j];
}

void swap (Key*a , int i, int j){
	swap(a[i], a[j]);
}


void swim(Key* a, int k, int N) {
	DPRINT(cout << ">swim key=" << a[k] << " @ k=" << k << " N=" << N << endl;);
	int k_saved = k;

    while(k>1 && comp(a, k/2, k)){
        swap(a, k/2, k);
        k = k / 2;
    }

	cout << "   N=" << N << " k=" << k_saved << " ";
	for (int i = 1; i <= N; i++) cout << a[i] << " ";
	cout << endl;
}

void sink(Key * a, int k, int N) {
	DPRINT(cout << ">sink key=" << a[k] << " @ k=" << k << " N=" << N << endl;);
	int k_saved = k;
    while(k*2 <= N){
        int child = 2*k; // 자식 노드 찾아가기
        if (child < N && ::comp(a, child, child+1)) child++; // 왼쪽 자식노드보다 오른쪽 자식노드가 더 크다면 바꿀 자식노드를 오른쪽 노드로 바꾼다.
        if (::comp(a, k, child)==false) break; // 현재 노드가 자식노드보다 작다면 더이상 바꿀 노드가 없으므로 반복 종료
        // 부모노드와 자식노드의 키 SWAP //
				swap(a, k, child);
        // 다음 노드로 이동 //
        k = child;
    }

	cout << "   N=" << N << " k=" << k_saved << " ";
	for (int i = 1; i <= N; i++) cout << a[i] << " ";
	cout << endl;
}

void heapsort(Key * a, int N) {
	int k;
	// 1st pass: restore the max heap property
	// start 'sink' at the last internal node and go up.
	cout << "1st pass(heapify - O(n)) begins:\n";
	int internal = N/2;
	while(internal >= 1){
		sink(a, internal--, N);
	}
	cout << "HeapOrdered: ";

	for (k = 1; k <= N; k++) cout << a[k] << " ";
	cout << endl;

	// 2nd pass: get the max out (from root while N > 1)
	// repeat 'swap and sink' at the root while decrementing N.
	cout << "2nd pass(swap and sink - n * O(log n) begins:\n";

	while(N>1){
		swap(a, 1 , N--);
		sink(a, 1, N);
	}
}

int grow(Key * a, Key key, int N) {

	a[++N] = key;
	swim(a, N, N);

	return N;
}

void show(Key * a, int N) {
	cout << "a[" << N << "]: ";
	for (int i = 1; i <= N; i++)
		cout << a[i] << " ";
	cout << endl;
}

// The first element(a[0]) is excluded.
int main(int argc, char* argv[]) {
#if 0
	char a[] = { ' ', 'H', 'A', 'P', 'P', 'Y', 'C', 'O', 'D', 'I', 'N', 'G', '\0', '\0' };
	int N = sizeof(a) / sizeof(a[0]) - 3;   // -3 because of 1st ' ' and last two'\0'.
#else
	char a[1024], line[1024];
	if (argc < 2) {
		cout << "Enter a word to sort: ";
		if (fgets(line, sizeof(line), stdin) == nullptr) exit(EXIT_FAILURE);
		// remove the new line character in line that returned from fgets().
		line[strcspn(line, "\r\n")] = 0; // works for LF, CR, CRLF, LFCR, ...
	}
	else {
		strcpy(line, argv[1]);
	}
	int N = strlen(line);
	a[0] = ' ';
	strcpy(&a[1], line);
#endif
	cout << "Input String:[" << a << "], N=" << N << endl;
	cout << "Input  ";
	show(a, N);

	// ascending order
	cout << "\nASCENDING:\n\n";
	comp = ::less;
	heapsort(a, N);
	show(a, N);

	cout << "\nDESCENDING:\n\n";
	comp = more;
	heapsort(a, N);
	show(a, N);

	cout << "\nGROWING: A, Z\n";
	N = grow(a, 'A', N);
	N = grow(a, 'Z', N);
	show(a, N);

	cout << "\nHappy coding~~\n";
	system("pause");
}

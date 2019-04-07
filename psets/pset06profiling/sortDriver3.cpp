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
#include "sort.h"
#define STARTING_SAMPLES 100

using namespace std;
void sortProfiling(void (*sortFunc)(int*, int), int *list, int n, int starting_samples = STARTING_SAMPLES);
void printList(int *list, int n, int max_print, int per_line);
void randomize(int list[], int n);

void randomize(int list[], int n) {
	DPRINT(cout << ">randomize...N=" << n << endl;)
	srand((unsigned)time(NULL));

	for(int i=0 ; i<n ; i++){
		list[i] = (rand() % n);
	}
	DPRINT(cout << "<randomize" << endl;)
}

void _printList(int *list, int N, int max_print, int per_line) {
	cout << "\t";
	for (int j=0 ; j<max_print ; j++){
		if (j%per_line==0){
			cout << "\n\t";
		}
		cout << list[j] << "\t";
	}
	for (int j=0 ; j<max_print ; j++){
		if (j%per_line==0){
			cout << "\n\t";
		}
		cout << list[N-max_print + j] << "\t";
		}
}

void printList(int *list, int N, int max_print, int per_line) {
	DPRINT(cout << ">printList...N=" << N << " max_print=" << max_print << endl;)

	if (max_print < N){
		_printList(list, N, max_print, per_line);
	}
	else{
		max_print = N/2;
		_printList(list, N, max_print, per_line);
		}

	cout << endl;
	DPRINT(cout << "<printList" << endl;)
}

// sortDriver to test sort functions or algorithms.
int main(int argc, char *argv[]) {
	int N = 0;						// default sample size
	int keyin;
	int *list = NULL;				// input and output buffer
	int max_print = 10;				// default max_print(=front_part+last_part)
	int per_line = max_print / 2;	// default samples per line to print
	clock_t start, end;
	char randomized = 'N';
	char option_char;
	char option_str[512];
	char algorithm_list[4][20] = {"Bubble", "Insertion", "Quicksort", "Selection"};
	enum algorithm_enum { BUBBLE, INSERTION, QUICKSORT, SELECTION };
	int  algorithm_chosen = SELECTION;  // default algorithm chosen
	void (*fn[]) (int* , int) = {bubbleSort, insertionSort, quickSort, selectionSort};
	DPRINT(cout << ">main...N=" << N << endl;)

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		sprintf(option_str, "[sort=%s N=%d randomized=%c max_print=%d per_line=%d]",
			algorithm_list[algorithm_chosen], N, randomized, max_print, per_line);
		cout << "\n\tOPTIONS: " << option_str << "\n"
			"\tn - number of samples size and initialize\n"
			"\tr - randomize(shuffle) samples\n"
			"\ta - algorithm to run\n"
			"\ts - sort()\n"
			"\tp - profiling()\n"
			"\tm - max samples to display at front or rear\n"
			"\td - max samples to display per line\n";


		option_char = GetChar("\tCommand(q to quit): ");
		DPRINT(cout << "option_char = " << option_char << endl;)

		switch (option_char) {
		case 'a': DPRINT(cout << "case = " << option_char << endl;)

			switch (GetChar("\tEnter b for bubble, i for insertion, s for selection, q for quick sort: ")) {
				case 'b':
					algorithm_chosen = BUBBLE;
					break;
				case 'i':
					algorithm_chosen = INSERTION;
					break;
				case 's':
					algorithm_chosen = SELECTION;
					break;
				case 'q':
					algorithm_chosen = QUICKSORT;
					break;
				default: {
					cout << "\tNo such an algorithm available. Try it again.\n"; break;
				}
			}

			//////////////
			break;

		case 'n': DPRINT(cout << "case = " << option_char;)

			keyin = GetInt("\tEnter input sample size: ");

			if (keyin <= STARTING_SAMPLES) {
				cout << "\tEnter a number much larger than " << STARTING_SAMPLES << ".\n";
				break;
			}

			N = keyin;

			if(list != NULL){
				delete (list);
				list = new int[N];
			}
			else{
				list = new int[N];
			}
			break;

		case 'r': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 1) {
				cout << "\tSet sample size first or larger\n";
				break;
			}

			randomize(list, N);
			randomized = 'Y';
			printList(list, N, max_print, per_line);

			break;

		case 's': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 0) {
				cout << "\tSet sample size first\n";
				break;
			}

			cout << "\tThe clock ticks and " << algorithm_list[algorithm_chosen] << " begins...\n";
			start = clock();

			(*fn[algorithm_chosen])(list, N);

			end = clock();
			randomized = 'N';

			printList(list, N, max_print, per_line);
			cout << "\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";


			break;

		case 'm': DPRINT(cout << "case = " << option_char << endl;)
			max_print = GetInt("\tinput max samples to display per line: ");
			break;

		case 'p' :
			sortProfiling(fn[algorithm_chosen], list, N, STARTING_SAMPLES);
			break;

		case 'd': DPRINT(cout << "case = " << option_char << endl;)
			per_line = GetInt("\tinput max samples to display per line: ");
			break;
		default:
			break;
		}
	} while (option_char != 'q');

	if (list != NULL) delete(list);
	// system("pause");
	DPRINT(cout << ">main" << endl;)
	return EXIT_SUCCESS;
}

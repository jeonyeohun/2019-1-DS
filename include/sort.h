/*
	On my Honour, I pledge that I have neither recieved nor provided improper assistance in the completion of this assignment.
	Signed: Jeon Yeo Hun
	Section: 03
	Student Number: 21500630
*/
#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

void insertionSort(int *list, int n, int(*comp)(int a, int b));
void selectionSort(int *list, int n, int(*comp)(int a, int b));
void quickSort(int *list, int n, int(*comp)(int a, int b));
void bubbleSort(int *list, int n, int(*comp)(int a, int b));
int ascending (int a, int b) {return a - b;}
int descending (int a, int b) {return b - a;}


#endif

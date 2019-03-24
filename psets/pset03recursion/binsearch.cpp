/*
 Include the following line at the top of your every source file with your name signed.
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: Jeon Yeo Hun Section: 03 Student Number: 21500630
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int _binary_search(int *data, int key, int lo, int hi) {
	DPRINT(cout << "key=" << key << " lo=" << lo << " hi=" << hi << endl;);

	if (key==data[(lo+hi)/2]){
		return (lo+hi)/2;
	}

	if (lo > hi) {
		if ((lo+hi)/2==0){
			return -1;
		}
		else{
			return -lo;
		}
	}
	if (key>data[(lo+hi)/2]){
		return _binary_search(data, key, (lo+hi)/2+1, hi);
	}
	else{
		return _binary_search(data, key, lo, (lo+hi)/2-1);
	}

}

int binary_search(int *list, int key, int size) {
	DPRINT(cout << ">binary_search: key=" << key << " size=" << size << endl;);
	int answer = _binary_search(list, key, 0, size-1);
	DPRINT(cout << "<binary_search: answer=" << answer << endl;);
	return answer;
}

#if 0
int main(int argc, char *argv[]) {
	int list[] = { 3, 5, 6, 9, 11, 12, 15, 16, 18, 19, 20 };
	int size = sizeof(list) / sizeof(list[0]);
	srand(time(NULL));

	cout << "list: ";
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
		cout << endl;

	for (int i=0 ; i< 10 ; i++){
		int key = rand()%20;
		int ans = binary_search(list, key, size);

		if (ans > size){
			cout << key << "\t is not @[" << 0 << "]"  << endl;
		}
		else if (ans < 0){
			cout << key << "\t is not @[" << ans*-1 << "]"  << endl;
		}

		else{
			cout << key << "\t is @[" << ans << "]"  << endl;
		}
	}
}
#endif

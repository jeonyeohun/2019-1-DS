/*
 * This program tests binary_search():
 *
 * The binary search algorithm is a method of searching a sorted array for a single
 * element by cutting the array in half with each recursive pass.The trick is to
 * pick a midpoint near the center of the array, compare the data at that point
 * with the data being searched and then responding to one of three possible
 * conditions : the data is found at the midpoint, the data at the midpoint is
 * greater than the data being searched for, or the data at the midpoint is less
 * than the data being searched for.
 * Recursion is used in this algorithm because with each pass a new array is
 * created by cutting the old one in half.The binary search procedure is then
 * called recursively, this time on the new (and smaller) array.
 * Typically, the array's size is adjusted by manipulating a beginning and
 * ending index. The algorithm exhibits a logarithmic order of growth because
 * it essentially divides the problem domain in half with each pass.
 *
 * In this example, you need an extra function at user's convenience since a
 * user may want to simply call the function with three parameters such as
 * binsearch(data, key, size).  Once you get the user's initial call,
 * then you call binary_search(data, key, lo, hi) recursively.
 *
 * To build this program:
 *  g++ binsearchDriver.cpp binsearch.cpp quicksort.cpp -o binsearch
 *
 * 2018/03/08	Creation
 * 2018/02/02	C++ Conversion
 */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void printList(int *list, int N, int max_print = 10, int per_line = 5);
void quickSort(int *a, int n);
int binary_search(int *list, int key, int size);

int main(int argc, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);		// print out immediately if any
	setvbuf(stdin,  NULL, _IONBF, 0);		// read input immediately if any

	vector<int> list; // array라고 생각하면 돼 C++에서는 제일 많이 쓰는게 String 과 vector String 은 문자열을 표현하기 편하고 vector는 데이터 타입을 담기 쉬는 배열이라고 생각하면 된다. 근데 벡터는 사이즈가 안정해져 있어서 add할때마다 사이즈가 자동으로 늘어난다. 요소를 넣을 때는 .push 지울때는 .back을 사용.
	string line;
	int keyin;
	cout << "Enter numbers to sort(q to quit): ";
	while (cin >> keyin) {
		cout << "your code here\n"		// adding to the end // 정수가 아닌 무언가를 마지막에 타이프를 하면 앞까지의 모든 정수를 다 벡터리스트에 저장한다.
	}

	int N = list.size(); // 와 이거 하면 바로 사이즈도 알 수 있당..
	cout << "\nUNSORTED[" << N << "]:\n";
	printList(&list[0], N); // 벡터로 만든건데 어레이처럼 접근이 가능하다!! 와우 신기방기..
	quickSort(&list[0], N); // 우리가 만들어둔 함수가 이미 C스타일로 정의되어 있기 때문에 어레이를 넘겨주는 것처럼 리스트와 길이를 알려주는 파라미터가 필요하다.
	cout << "\nSORTED[" << N << "]:\n";
	printList(&list[0], N);

	srand((unsigned)time(NULL));	// comment out when debugging

	// get a random number to use as a key for testing the binary search.
	cout << "your code here\n"

	cout << "\n\t" << key << " To Be Found.\n";

	// invoke bineary_search to find key in the list.
	// display the result

  cout << "your code here\n"

	// print a few data around a possible key index or -index to check your output.
	int extra = 4;						// a magic number

	cout << "your code here\n" // 이건 양심상 해야되는 부분....교수님이 다 해주셨는데 이거 못하면 양심이 없는거...

	cout << "Happy Coding~~\n";
	// system("pause");
	return EXIT_SUCCESS;
}

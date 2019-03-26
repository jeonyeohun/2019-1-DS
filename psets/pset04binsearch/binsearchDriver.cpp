/*
	 Include the following line at the top of your every source file with your name signed.
	 On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
	 Signed: Jeon Yeo Hun Section: 03 Student Number: 21500630
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
		list.push_back(keyin);		// adding to the end // 정수가 아닌 무언가를 마지막에 타이프를 하면 앞까지의 모든 정수를 다 벡터리스트에 저장한다.
	}

	int N = list.size(); // 와 이거 하면 바로 사이즈도 알 수 있당..
	cout << "\nUNSORTED[" << N << "]:\n";
	printList(&list[0], N); // 벡터로 만든건데 어레이처럼 접근이 가능하다!! 와우 신기방기..
	quickSort(&list[0], N); // 우리가 만들어둔 함수가 이미 C스타일로 정의되어 있기 때문에 어레이를 넘겨주는 것처럼 리스트와 길이를 알려주는 파라미터가 필요하다.
	cout << "\nSORTED[" << N << "]:\n";
	printList(&list[0], N);

	srand((unsigned)time(NULL));	// comment out when debugging

	// get a random number to use as a key for testing the binary search.
	int key = rand() % list[N-1];

	cout << "\t" << key << " To Be Found.\n";

	// invoke bineary_search to find key in the list.
	// display the result

  int ans = binary_search(&list[0], key, N);

	if (ans == N)
		cout << "\t" << key << " is not @[0]"  << endl;
	else if (ans < 0)
		cout << "\t" << key << " is not @[" << ans*-1 << "]"  << endl;
	else
		cout << "\t" << key << " is @[" << ans << "]"  << endl;

	if (ans<0){ans*=-1;}
	// print a few data around a possible key index or -index to check your output.
	int extra = 4;						// a magic number
	for (int i=(ans-extra) ; i< ans ; i++){
		if (i < 0){
			i = 0;
		}
		cout << "\t[" << i << "]" << "=" << list[i] << endl;
	}
	for (int i=ans ; i<= ans+extra ; i++){
		cout << "\t[" << i << "]" << "=" << list[i] << endl;
		if ((i+1) >= N){
			break;
		}
	}
	// 이건 양심상 해야되는 부분....교수님이 다 해주셨는데 이거 못하면 양심이 없는거...

	cout << "Happy Coding~~\n";
	// system("pause");
	return EXIT_SUCCESS;
}

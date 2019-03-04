/*
	On my Honour, I pledge that I have neither recieved nor provided improper assistance in the completion of this assignment.
	Signed: Jeon Yeo Hun
	Section: 03
	Student Number: 21500630
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
		string str;
		// 프로그램 실행 시 전달되는 문자열이 없을 때 //
		if(argc == 1){
			while(1){
				str = ""; // 반복될 때마다 문자열을 초기화
				cout << "Enter your name: ";
		  	getline (cin, str);

				if (str == ""){ // 문자열에 변화가 없었다면 반복문 종료
					break;
				}
				cout << "Hello " + str << "!\n";
			}

			cout << "Hello World!" << endl;
		}
		// 프로그램 실행 시 전달되는 문자열이 있을 때 //
		else{
			cout << "Hello ";
			for (int i = 1; i < argc; i++)
				cout << argv[i];
			cout << "!\n";
		}
    return EXIT_SUCCESS;
}

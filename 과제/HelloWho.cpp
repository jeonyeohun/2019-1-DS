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

		if(argc == 1){
			while(1){
				str = "";
				cout << "Enter your name: ";
		  	getline (cin, str);

				if (str == ""){
					break;
				}

				cout << "Hello " + str << "!\n";
			}

			cout << "Hello World!" << endl;
		}
		else{
			cout << "Hello ";
			for (int i = 1; i < argc; i++){
				cout << argv[i];
			}
			cout << "!\n";
		}
    return EXIT_SUCCESS;
}

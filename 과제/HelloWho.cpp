/**
	HelloWho.cpp by idebtor@gmail.com
	It prints "Hello World!" on the console or
	"Hello" with a given name.

	To build the program which generates hellowho.exe:
	> g++ HelloWho.cpp -o hello

	To run the program without a command line argument:
	> ./hello
	> Enter a name:

	To run the program with a command line argument:
	> ./hello Dr. John Kim
	> Hello Dr. John Kim!

	02/10/19: Created
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    // Use setvbuf() to prevent the output from buffered on console.
    // setvbuf(stdout, NULL, _IONBF, 0);
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
	    // Use system("pause") to prevent the terminal from disappearing
	    // as soon as the program terminates such as Visual Studio sometimes.
	    // system("pause");
		}
		else{
			cout << "Hello ";
			for (int i = 1; i < argc; i++)
				cout << argv[i] << "!";
			cout << "\n";
		}
    return EXIT_SUCCESS;
}

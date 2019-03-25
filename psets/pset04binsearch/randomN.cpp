/*
 	Include the following line at the top of your every source file with your name signed.
	On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
	Signed: Jeon Yeo Hun Section: 03 Student Number: 21500630
 */
#include <iostream>
#include <ctime>

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int main(int argc, char *argv[]) {
	int N = 0;
	char *end;

	// The strtol() converts the contents of a string as an integral
	// number of the specified base and return its value as a long int.
	// s: specifies the string which has the representation of an int.
	// end: refers to an already allocated object of type char*.
	//      The value of the end is set by the function to the next
	//      character in s after the last valid character. It can
	//      also be a null pointer, in which case it is not used.
	// b: specifies to the base of the integral value.
	// Return Value : The function returns value of two types :
	// - If a valid conversion occurs, then a long int value is returned,
	//   *end is NULL. If not, then 0 is returned and *end is not NULL.

	if (argc == 2)
		N = strtol(argv[1], &end, 10);

	if (N <= 0 || *end != '\0') {
		std::cout << "Usage: randomN N\n";
		return EXIT_FAILURE;
	}

	// rand() returns a random number between 0 and RAND_MAX which is
	// defined in stdlib.h or cstdlib.
	// RAND_MAX is surprisingly small (0~32767) and also depends on
	// its implementation, but guaranteed at least 32767. The
	// following program will work for random values in the
	// range[0, (RAND_MAX + 1)*(RAND_MAX + 1)).
	// Refer to random.pdf to complete the following code.

	DPRINT(int min = (RAND_MAX + 1)*(RAND_MAX + 1););
	DPRINT(int max = -1;);

	//srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int r = (rand() * (RAND_MAX + 1) + rand()) % N;
		std::cout << r << std::endl;

		DPRINT(if (r > max) max = r; else if (r < min) min = r;);
	}

	DPRINT(std::cout << min << "~" << max << std::endl;);
	return EXIT_SUCCESS;
}

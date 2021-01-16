#include "lib.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	clock_t start, end;
	
	cout << "Solo thread: " << endl;
	start = clock();
	
	cout << "Result: " << soloThread() << endl;
	
	end = clock();
	cout << "Time: " << (end - start) / 1000 << " sec" << endl << endl;
	
	cout << "Multi thread: " << endl;
	start = clock();
	
	cout << "Result: " << multiThread() << endl;
	
	end = clock();
	cout << "Time: " << (end - start) / 1000 << " sec" << endl;
    return 0;
}

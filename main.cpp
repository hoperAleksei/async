#include "lib.h"
#include <cstring>
#include <iostream>


using namespace std;

int main() {
	
	char inp[1000] = "Hello, World!";
	char out[1000];
	
	encode(out, inp);
	
	cout << out << endl;
	
	strcpy(inp, out);
	
	decode(out, inp);
	
	cout << out;
	
	
    return 0;
}

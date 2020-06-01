// g++ -pthread -std=c++14 -O3 -o parity parity.cc
#include "test_framework/generic_test.h"
#include <iostream>
#include <bitset>

short Parity(unsigned long long x) {
	short result = 0;
	// Printing Debugging
	std::cout << x ;		     // Random decimal input
	std::cout << " ";
	std::bitset<64> y(x);
	std::cout << y << std::endl; // Prints exact bits representaiton of random input
	while (x) {                  
		result ^= (x & 1);		 // XOR operator with previous result and (x and 1), if one end bit is 1
		x >>= 1;				 // shift to right bit
		
	}
	std::cout << result << std::endl;
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}

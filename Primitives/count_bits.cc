#include "test_framework/generic_test.h"
#include <iostream>

short CountBits(unsigned int x) {
	short num_bits = 0;
	while(x) {
		num_bits += x & 1;              // add assignment 
		x >>= 1;                        // right shift by one operator
	}
	std::cout << num_bits << std::endl; // print number of bits
  return num_bits;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "count_bits.cc", "count_bits.tsv", &CountBits,
                         DefaultComparator{}, param_names);
}

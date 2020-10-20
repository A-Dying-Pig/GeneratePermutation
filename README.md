# Generate Permutation
This repository contains 2 algorithms to generate permutations:

1. Dictionary Order Algorithm
2. SJT Algorithm

For every algorithm, any specific **permutation** maps to an **index** one by one and any index maps to an **median number** one by one (thus **median number** maps to permutation one by one). **Median number** stores permutation position information and therefore can recover the permutation in turn. Median number is not decimal-based but can be converted to decimal-based number. The decimal-based number is index from 0 to N!-1 (N is the number of elements involved in permutation).

When involving N elements in permutation, integers from 1 to N (1 and N included) are used to represent different elements.

To compile and run the program:
mkdir build
cd build
cmake ..
make
./GeneratePermutation

Time and Space Complexity are considered for comparison. Experiments are on 2.9 GHz double Intel Core i5 WITH 8 GB 1867 MHz DDR3 Macbookpro. Please check experiment folder for running screenshot.

If you want to use the library by yourself. Please include Permutation.hpp and certain algorithm's header file (such as SJT.hpp,Dictionary.hpp) and compile corresponding cpp file to run the program. Check the interfaces and notes in class Permutation.
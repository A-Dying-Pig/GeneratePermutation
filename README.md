# Generate Permutation
This repository contains four algorithms to generate permutations:

1. Dictionary Order Algorithm
2. SJT Algorithm
3. Ascending Number System Algorithm
4. Descending Number System Algorithm

For every algorithm, any specific **permutation** maps to an **index** one by one and any index maps to an **median number** one by one (thus **median number** maps to permutation one by one). **Median number** stores permutation position information and therefore can recover the permutation in turn. Median number is not decimal-based but can be converted to decimal-based number. The decimal-based number is index from 0 to N!-1 (N is the number of elements involved in permutation).

When involving N elements in permutation, integers from 1 to N (1 and N included) are used to represent different elements.

Time and Space Complexity are considered for comparison. 
On 2.9 GHz double Intel Core i5 WITH 8 GB 1867 MHz DDR3 Macbookpro:
generating every 11-element permutation, SJT uses 32660 ms ,Dictionary uses 31202 ms.

Please include Permutation.hpp and certain algorithm's header file (such as SJT.hpp,Dictionary.hpp) and compile corresponding cpp file to run the program. Check the interfaces and notes in class Permutation.

#include <iostream>
#include "Permutation.hpp"
#include "SJT.hpp"
#include "Dictionary.hpp"
using namespace std;



void test(){
  Permutation* p1 = new SJT(10,NEIGHBOR);
  p1->generate_all_permutation();
  // p1->print_all_permutation();
  Permutation* p2 = new Dictionary(10,DICT);
  p2->generate_all_permutation();
  // p2->print_all_permutation();

  //test median 2 permutation
  // vector<int> median = p1->index2median(362879);
  // output_vector(median);
  // vector<int> perm = p1->median2permutation(median);
  // output_vector(perm);
  // test permutation 2 median
  // output_vector(p2->permutation2median(perm));
  // test index 2 permutation 
  // int temp;
  // cin >> temp;
  // output_vector(p->index2permutation(temp));
}


int main(){
  test();
  return 0;
} 
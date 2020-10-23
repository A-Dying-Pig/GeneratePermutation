#include <iostream>
#include <ctime>
#include "Permutation.hpp"
#include "SJT.hpp"
#include "Dictionary.hpp"
#include "Ascending.hpp"
#include "Descending.hpp"
using namespace std;

void testing(){
  for (int i = 4; i < 11; i ++)
  {
    Permutation* p1 = new SJT(i,NEIGHBOR);
    Permutation* p2 = new Dictionary(i,DICT);
    Permutation* p3 = new Ascending(i,INC);
    Permutation* p4 = new Descending(i,DEC);
    p1->permutation();
    p2->permutation();

    p1->permutation_from_index();
    p2->permutation_from_index();
    p3->permutation_from_index();
    p4->permutation_from_index();

    p1->permutation_iteration();
    p1->permutation_iteration_improve();
  }
}

int main(){
  testing();
  return 0;
} 
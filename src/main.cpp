#include <iostream>
#include "Permutation.hpp"
#include "SJT.hpp"
using namespace std;

int main(){
  Permutation* p = new SJT(10,NEIGHBOR);
  long val = ascending2decimal(number2vec(67342221,8));
  cout << val<<endl;

  vector<int> ret = decimal2ascending(279905,8);
  for (int i = 0; i < ret.size(); i++)
    cout << ret[i] <<endl;
  return 0;
} 
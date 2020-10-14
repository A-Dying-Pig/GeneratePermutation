#include "Permutation.hpp"
#include <vector>
using namespace std;

#ifndef _SJT_H_
#define _SJT_H_

class SJT: public Permutation
{
public:
    SJT(int n,PermutationType t):Permutation(n,t){}
    vector<int> index2median(long index);
    vector<int> median2permutation(vector<int> median);
    vector<int> permutation2median(vector<int> perm);
    long median2index(vector<int> median);
    vector<int> index2permutation(long index);
    long permutation2index(vector<int> perm);
    long generate_all_permutation();
    void print_all_permutation();

};



#endif
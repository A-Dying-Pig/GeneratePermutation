#include "Permutation.hpp"
#include <vector>
using namespace std;

#ifndef _SJT_H_
#define _SJT_H_

class SJT: public Permutation
{
public:
    SJT(int n,PermutationType t):Permutation(n,t){}
    long index2median(long index);
    vector<int> median2permutation(long median);
    long permutation2median(vector<int> perm);
    long median2index(long median);
    vector<int> index2permutation(long index);
};



#endif
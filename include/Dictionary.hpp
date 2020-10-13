#include "Permutation.hpp"
#include <vector>
using namespace std;

#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

class Dictionary: public Permutation
{
public:
    Dictionary(int n,PermutationType t):Permutation(n,t){}
    vector<int> index2permutation(long index);
};



#endif
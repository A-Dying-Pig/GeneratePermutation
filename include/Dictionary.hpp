#include "Permutation.hpp"

#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

class Dictionary: public Permutation
{
public:
    Dictionary(int n,PermutationType t):Permutation(n,t){}
    void list_all_permutation();
    long index2permutation(long index);
};



#endif
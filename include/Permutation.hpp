#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_


enum PermutationType{
    DICT,INC,DEC,NEIGHBOR
};

class Permutation
{
    //class Permutation is the base class for 4 specific permutation class
    //class Permutation defines common interfaces, whose functions are achieved by 4 specific permutation class
protected:
    int number;
    PermutationType type;
public:
    Permutation(int n,PermutationType t):number(n),type(t){}
    ~Permutation(){}
    virtual void list_all_permutation() = 0;
    // virtual long index2permutation(long index);
};


#endif
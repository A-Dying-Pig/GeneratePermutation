#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_

#include <vector>
using namespace std;


/**
 * class Permutation is the base class for 4 specific permutation class
 * class Permutation defines common interfaces, which are achieved by specific permutation class
 * 
 * 
 * 
 * 
 * 
 */

enum PermutationType{
    DICT,       // Dictionary Order 
    INC,
    DEC,
    NEIGHBOR    // SJT Order
};

class Permutation
{
protected:
    int N; // permutation is among integer from 1 to [N]
    PermutationType type;
public:
    Permutation(int n,PermutationType t):N(n),type(t){}
    ~Permutation(){}
    virtual long index2median(long index) = 0;
    virtual vector<int> median2permutation(long median) = 0;
    virtual long permutation2median(vector<int> perm) = 0;
    virtual long median2index(long median) = 0;
    virtual vector<int> index2permutation(long index) = 0;
};

//convertion between decimal number and ascending/descending number
vector<int> decimal2descending(long val, int N);
long descending2decimal(vector<int> val);
vector<int> decimal2ascending(long val, int N);
long ascending2decimal(vector<int> val);
vector<int> number2vec(long val, int N);


#endif
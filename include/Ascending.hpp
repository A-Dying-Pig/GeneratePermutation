#include "Permutation.hpp"
#include <vector>
using namespace std;

#ifndef _Ascending_H_
#define _Ascending_H_

class Ascending: public Permutation
{
public:
    Ascending(int n,PermutationType t):Permutation(n,t){}
    vector<int> index2median(long index);
    vector<int> median2permutation(vector<int> median);
    vector<int> permutation2median(vector<int> perm);
    long median2index(vector<int> median);
    vector<int> index2permutation(long index);
    long permutation2index(vector<int> perm);
    vector< vector<int> > permutation_from_index();
    vector< vector<int> > permutation();
    void print_all_permutation();
    vector<int> next(vector<int> perm);
    vector<int> next_improve(vector<int> perm);
    vector<vector<int> > permutation_iteration();
    vector<vector<int> > permutation_iteration_improve();
};



#endif
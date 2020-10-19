#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_

#include <vector>
#include <iostream>
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
    unsigned int N; // permutation is among integer from 1 to [N]
    PermutationType type;
    long max_index;
public:
    Permutation(int n,PermutationType t);
    ~Permutation(){}
    /* Convert index to median number
    * @param index: index in decimal
    * @return: median number
    */
    virtual vector<int> index2median(long index) = 0;

    /* Get permutation from median number
    * @param median: median number
    * @return: permutaion
    */
    virtual vector<int> median2permutation(vector<int> median) = 0;

    /* Get median number from permutation
    * @param perm: permutation
    * @return: median number
    */
    virtual vector<int> permutation2median(vector<int> perm) = 0;

    /* Convert median number to index
    * @param median: median number
    * @return: index in decimal
    */
    virtual long median2index(vector<int> median) = 0;

    /* Get permutation from index
    * @param index: index in decimal
    * @return: permutation
    */
    virtual vector<int> index2permutation(long index) = 0;

    /* Get index from permutation
    * @param perm: permutation
    * @return: index in decimal
    */
    virtual long permutation2index(vector<int> perm) = 0;

    /*traverse index to generate all permutation
    * @return: all permutation
    */
    virtual vector< vector<int> > permutation_from_index() = 0;

    /* use original algorithm to generate all
    * if there is no original algorithm, set sub-class corresponding function empty
    * @return: all permutations
    */
    virtual vector< vector<int> > permutation() = 0;

    /* print all permuatation*/
    virtual void print_all_permutation() = 0;

    /* use original algorithm to next permutation
    * @return: next permutation
    */
    virtual vector<int> next(vector<int> perm) = 0;

    /* use original algorithm to next permutation with improvement
    * @return: next permutation
    */
    virtual vector<int> next_improve(vector<int> perm) = 0;

    virtual vector<vector<int> > permutation_iteration() = 0;
    virtual vector<vector<int> > permutation_iteration_improve() = 0;

};

//convertion between decimal number and ascending/descending number
vector<int> decimal2descending(long val, int N);
long descending2decimal(vector<int> val);
vector<int> decimal2ascending(long val, int N);
long ascending2decimal(vector<int> val);
void output_vector(vector<int> val);
vector<int> input_vector();



#endif
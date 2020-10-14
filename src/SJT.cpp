#include "SJT.hpp"
#include <iostream>
#include <ctime>


vector<int> SJT::index2median(long index)
{return decimal2descending(index,N-1);}


vector<int> SJT::median2permutation(vector<int> median)
{   
    vector<int> perm(N,0);
    if (median.size() != N-1)
    {
        cout << "ERROR! N permuation needs N-1 digit median number"<<endl;
        return perm;
    }
    vector<bool> direction;     // false for left, true for right
    direction.push_back(false); // b2 always left
    int odd_even = 0,counter = 0,z = 0;
    for (int i = 1; i < N - 1; i++)
    {
        if (i % 2)
            odd_even = median[i-1];
        else 
            odd_even = median[i-1] + median[i-2];
        direction.push_back(odd_even % 2);
    }
    for (int i = N-2; i >= 0; i--)
    {
        counter = 0;
        for(int j = 0; j < N; j++)
        {
            z = direction[i] * j + (1 - direction[i]) * (N - 1 - j);
            if (perm[z] == 0)
            {
                if (counter == median[i])
                {                
                    perm[z] = i + 2;
                    break;
                }
                counter ++;
            }
        }
    }
    for (int i = 0; i < N; i ++)
        if(!perm[i])
        {
            perm[i] = 1;
            break;
        }
    return perm;
}


vector<int> SJT::permutation2median(vector<int> perm)
{
    vector<int> median(N-1);
    if (perm.size() != N)
    {
        cout << "ERROR! Permutation should have N elements, only "<<perm.size()<<" elements are found"<<endl;
        return median;
    }
    for(int j = N - 1; j >= 0; j-- )
    {
        if (perm[j] == 1)
        {
            median[0] = 1;  //get b2
            break;
        }else if(perm[j] == 2)
            break;
    }
    int odd_even = 0,right_less = 0;
    bool direction = 0;
    for (int i = 1; i <  N - 1; i++)
    {
        if (i % 2)
            odd_even = median[i-1];
        else 
            odd_even = median[i-1] + median[i-2];
        direction = odd_even % 2;
        right_less = 0;
        for(int j = N-1; j >= 0; j--)
        {
            if (perm[j] < i + 2)
                right_less ++;
            else if (perm[j] == i + 2)
                break;
        }
        median[i] = ( (1 - direction) * right_less + direction * (i + 1 - right_less));
    }
    return median;
}


long SJT::median2index(vector<int> median)
{return descending2decimal(median);}


vector<int> SJT::index2permutation(long index)
{return median2permutation(index2median(index));}


long SJT::permutation2index(vector<int> perm)
{return median2index(permutation2median(perm));}


long SJT::generate_all_permutation()
{
    long start = clock();
    for (int i = 0; i <= max_index; i++)
        index2permutation(i);
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using SJT Algorithm spends "<<ms <<" ms"<<endl;
    return ms;
}

void SJT::print_all_permutation()
{for (int i = 0; i <= max_index; i++) output_vector(index2permutation(i));}


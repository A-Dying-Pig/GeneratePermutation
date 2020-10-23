#include "Descending.hpp"
#include <iostream>
#include <ctime>


vector<int> Descending::index2median(long index)
{return decimal2descending(index,N-1);}


vector<int> Descending::median2permutation(vector<int> median)
{   
    vector<int> perm(N,0);
    if (median.size() != N-1)
    {
        cout << "ERROR! N permuation needs N-1 digit median number"<<endl;
        return perm;
    }
    int counter = 0;
    vector<bool> number_free(N,true);  //index z correspond to number z + 1
    for (int i = N - 2; i >= 0; i--)
    {
        counter = 0;
        for (int j = N - 1; j >= 0; j--)
        {
            if(number_free[j] && counter == median[i])
            {
                perm[j] = i + 2;
                number_free[j] = false;
                break;
            }
            counter += number_free[j];
        }
    }
    for (int j = N-1; j >= 0; j--)
        if(number_free[j])
        {
            perm[j] = 1;
            break;
        }    
    return perm;
}


vector<int> Descending::permutation2median(vector<int> perm)
{
    vector<int> median(N-1);
    if (perm.size() != N)
    {
        cout << "ERROR! Permutation should have N elements, only "<<perm.size()<<" elements are found"<<endl;
        return median;
    }

    int counter = 0;

    for (int i = 0; i < N; i++)
    {
        if (perm[i] > 1)
        {   
            counter = 0;
            for (int j = i + 1; j < N; j++)
                if (perm[j] < perm[i])
                    counter ++;
            median[perm[i] - 2] = counter;
        }
    }
    return median;
}


long Descending::median2index(vector<int> median)
{return descending2decimal(median);}


vector<int> Descending::index2permutation(long index)
{return median2permutation(index2median(index));}


long Descending::permutation2index(vector<int> perm)
{return median2index(permutation2median(perm));}


vector< vector<int> > Descending::permutation_from_index()
{
    vector< vector<int> > ret;
    long start = clock();
    for (int i = 0; i <= max_index; i++)
        ret.push_back(index2permutation(i));
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using Descending Algorithm by traversing index spends "<<ms <<" ms"<<endl;
    return ret;
}

vector<int> Descending::next(vector<int> perm)
{
    long idx = permutation2index(perm);
    long idx1 = idx + 1;
    return index2permutation(idx1);
}

vector<int> Descending::next_improve(vector<int> perm)
{}


vector<vector<int> > Descending::permutation_iteration()
{}


vector<vector<int> > Descending::permutation_iteration_improve()
{}


vector< vector<int> > Descending::permutation()
{
    long start = clock();
    vector< vector<int> > ret;
    vector<int> perm1(N,0);  // index[i] correspond to number i+1 position

    for (int i = 0; i <= max_index; i++)
    {
        perm1 = index2permutation(i);
        ret.push_back(perm1);
    }
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using Descending Algorithm spends "<<ms <<" ms"<<endl;
    return ret;
}

void Descending::print_all_permutation()
{for (int i = 0; i <= max_index; i++) output_vector(index2permutation(i));}


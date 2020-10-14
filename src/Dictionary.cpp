#include "Dictionary.hpp"
#include <iostream>
#include <ctime>


vector<int> Dictionary::index2median(long index)
{return decimal2ascending(index,N-1);}


vector<int> Dictionary::median2permutation(vector<int> median)
{   
    vector<int> perm(N,0);
    if (median.size() != N-1)
    {
        cout << "ERROR! N permuation needs N-1 digit median number"<<endl;
        return perm;
    }
    int counter = 0;
    vector<bool> number_free(N,true);  //index z correspond to number z + 1
    for (int i = 0; i < N - 1; i++)
    {
        counter = 0;
        for (int j = 0; j < N; j++)
        {
            if (number_free[j] && counter == median[i])
            {
                perm[i] = j + 1;
                number_free[j] = false;
                break;
            }
            counter += number_free[j];
        }
    }
    for (int j = 0; j < N; j++)
        if(number_free[j])
        {
            perm[N-1] = j + 1;
            break;
        }    
    return perm;
}


vector<int> Dictionary::permutation2median(vector<int> perm)
{
    vector<int> median(N-1);
    if (perm.size() != N)
    {
        cout << "ERROR! Permutation should have N elements, only "<<perm.size()<<" elements are found"<<endl;
        return median;
    }
    median[0] = perm[0] - 1;
    int counter = 0;
    for (int i = 1; i < N - 1; i++)
    {
        counter = 0;
        for (int j = i + 1; j < N; j++)
            if (perm[j] < perm[i])
                counter ++;
        median[i] = counter;
    }
    return median;
}


long Dictionary::median2index(vector<int> median)
{return ascending2decimal(median);}


vector<int> Dictionary::index2permutation(long index)
{return median2permutation(index2median(index));}


long Dictionary::permutation2index(vector<int> perm)
{return median2index(permutation2median(perm));}


long Dictionary::generate_all_permutation()
{
    long start = clock();
    for (int i = 0; i <= max_index; i++)
        index2permutation(i);
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using Dictionary Algorithm spends "<<ms <<" ms"<<endl;
    return ms;
}

void Dictionary::print_all_permutation()
{for (int i = 0; i <= max_index; i++) output_vector(index2permutation(i));}


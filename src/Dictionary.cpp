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


vector< vector<int> > Dictionary::permutation_from_index()
{
    vector< vector<int> > ret;
    long start = clock();
    for (int i = 0; i <= max_index; i++)
        ret.push_back(index2permutation(i));
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using Dictionary Algorithm by traversing index spends "<<ms <<" ms"<<endl;
    return ret;
}

vector<int> Dictionary::next(vector<int> perm)
{
    int j = 0, z = 0, p = 0, temp = 0;   
    for(j = N - 1; j >=1 ; j--)
            if (perm[j - 1] < perm[j])
                break;
    //find the min in the end series
    for(z = N - 1; z >= j; z--)
            if(perm[z] > perm[j-1])
            break;
     // swap
    temp = perm[j - 1];
    perm[j - 1] = perm[z];
    // get the min end series
    for (p = j ; p < N ; p ++)
        if(temp > perm[p])
            break;
    vector<int> inter;
    if (p == N)
    inter.push_back(temp);
    for (int q = N-1; q >= j; q--)
    {
        if(q != z)
            inter.push_back(perm[q]);
        if(q == p)
            inter.push_back(temp);
    }
    for (int q = j; q < N; q++)
        perm[q] = inter[q - j];
    return perm;  
}

vector<int> Dictionary::next_improve(vector<int> perm)
{}


vector<vector<int> > Dictionary::permutation_iteration()
{}


vector<vector<int> > Dictionary::permutation_iteration_improve()
{}


vector< vector<int> > Dictionary::permutation()
{
    long start = clock();
    vector< vector<int> > ret;
    vector<int> perm1(N,0);  // index[i] correspond to number i+1 position
    for (int i = 0; i < N; i++)
    {
        perm1[i] = i + 1;
    }
    ret.push_back(perm1);

    int j = 0, z = 0, p = 0, temp = 0;
    for (int i = 1; i <= max_index; i++)
    {
        for(j = N - 1; j >=1 ; j--)
            if (perm1[j - 1] < perm1[j])
                break;
        //find the min in the end series
        for(z = N - 1; z >= j; z--)
            if(perm1[z] > perm1[j-1])
                break;
        // swap
        temp = perm1[j - 1];
        perm1[j - 1] = perm1[z];
        // get the min end series
        for (p = j ; p < N ; p ++)
            if(temp > perm1[p])
                break;
        vector<int> inter;
        if (p == N)
        inter.push_back(temp);
        for (int q = N-1; q >= j; q--)
        {
            if(q != z)
                inter.push_back(perm1[q]);
            if(q == p)
                inter.push_back(temp);
        }
        for (int q = j; q < N; q++)
            perm1[q] = inter[q - j];
        ret.push_back(perm1);
    }
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using Dictionary Algorithm spends "<<ms <<" ms"<<endl;
    return ret;
}

void Dictionary::print_all_permutation()
{for (int i = 0; i <= max_index; i++) output_vector(index2permutation(i));}


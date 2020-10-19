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


vector< vector<int> > SJT::permutation_from_index()
{
    vector< vector<int> > ret;
    long start = clock();
    for (int i = 0; i <= max_index; i++)
        ret.push_back(index2permutation(i));
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using SJT Algorithm by traversing index spends "<<ms <<" ms"<<endl;
    return ret;
}

void SJT::print_all_permutation()
{for (int i = 0; i <= max_index; i++) output_vector(index2permutation(i));}


vector<bool> SJT::permutation2direction(vector<int> perm)
{
    vector<bool> directions;
    vector<int> median(N-1);
    if (perm.size() != N)
    {
        cout << "ERROR! Permutation should have N elements, only "<<perm.size()<<" elements are found"<<endl;
        return directions;
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
    directions.push_back(false);
    directions.push_back(false);
    bool direction = 0;
    for (int i = 1; i < N-1; i++)   //median i+2 direction-i+2
    {
        if (i % 2)
            odd_even = median[i-1];
        else 
            odd_even = median[i-1] + median[i-2];
        direction = odd_even % 2;
        directions.push_back(direction);
        right_less = 0;
        for(int j = N-1; j >= 0; j--)
        {
            if (perm[j] < i + 2)
                right_less ++;
            else if (perm[j] == i + 2)
                break;
        }
        median[i] = ((1 - direction) * right_less + direction * (i + 1 - right_less));
    }
    return directions;
}

vector<bool> SJT::permutation2direction_improve(vector<int> perm)
{
    vector<bool> directions;
    vector<int> median(N-1);
    if (perm.size() != N)
    {
        cout << "ERROR! Permutation should have N elements, only "<<perm.size()<<" elements are found"<<endl;
        return directions;
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
    int right_less = 0,s = 0;
    directions.push_back(false);
    directions.push_back(false);
    bool direction = 0;
    for (int i = 1; i <  N - 1; i++)
    {
        s = s * (i - 1) + median[i-1];
        direction = s % 2;
        directions.push_back(direction);
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
    return directions;
}

vector<int> SJT::next(vector<int> perm)
{
    vector<int> index_pos(N,0);
    vector<bool> direction = permutation2direction(perm);
    int next_index = 0, j = 0, neighbor_value = 0;
    for (int i = 0; i < N; i++)
        index_pos[perm[i] - 1] = i;
    for (j = N-1; j >= 0; j--)
    {
        next_index = index_pos[j] + 2 * direction[j] - 1;  
        if(next_index < 0 || next_index  >= N)
            continue;
        neighbor_value = perm[next_index];
        if(j + 1 > neighbor_value)
            break;
    }
    // swap
    perm[next_index] = j+1;
    perm[index_pos[j]] = neighbor_value;
    return perm;
}

vector<int> SJT::next_improve(vector<int> perm)
{
    vector<int> index_pos(N,0);
    vector<bool> direction = permutation2direction_improve(perm);
    int next_index = 0, j = 0, neighbor_value = 0;
    for (int i = 0; i < N; i++)
        index_pos[perm[i] - 1] = i;
    for (j = N-1; j >= 0; j--)
    {
        next_index = index_pos[j] + 2 * direction[j] - 1;  
        if(next_index < 0 || next_index  >= N)
            continue;
        neighbor_value = perm[next_index];
        if(j + 1 > neighbor_value)
            break;
    }
     // swap
    perm[next_index] = j+1;
    perm[index_pos[j]] = neighbor_value;
    return perm;
}   


vector<vector<int> > SJT::permutation_iteration()
{
    long start = clock();
    vector<vector<int> > ret;
    vector<int> perm = index2permutation(0);
    ret.push_back(perm);
    for (int i = 0; i < max_index; i++)
    {
        perm = next(perm);
        ret.push_back(perm);
    }
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using SJT Algorithm by iteration spends "<<ms <<" ms"<<endl;
    return ret;
}

vector<vector<int> > SJT::permutation_iteration_improve()
{
    long start = clock();
    vector<vector<int> > ret;
    vector<int> perm = index2permutation(0);
    ret.push_back(perm);
    for (int i = 0; i < max_index; i++)
    {
        perm = next_improve(perm);
        ret.push_back(perm);
    }
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using SJT Algorithm by iteration with improvement spends "<<ms <<" ms"<<endl;
    return ret;
}


vector<vector<int> > SJT::permutation()
{
    vector<vector<int> > ret;
    long start = clock();
    // first one;
    vector<int> perm1(N,0),index_pos(N,0);  // index[i] correspond to number i+1 position
    for (int  i = 0; i < N; i++)
    {
        perm1[i] = i + 1;
        index_pos[i] = i;
    }
    ret.push_back(perm1);
    vector<bool> direction(N,false);        // false for left; true for right - directoin[i] coresspond to number i+1 direction
    int next_index = 0, j = 0, neighbor_value = 0;
    for (int i = 1; i <= max_index; i++)
    {
        //find largest movable number - j+1 and next index pos
        for (j = N-1; j >= 0; j--)
        {
            next_index = index_pos[j] + 2 * direction[j] - 1;  
            if(next_index < 0 || next_index  >= N)
                continue;
            neighbor_value = perm1[next_index];
            if(j + 1 > neighbor_value)
                break;
        }
        // swap
        perm1[next_index] = j+1;
        perm1[index_pos[j]] = neighbor_value;
        index_pos[neighbor_value - 1] = index_pos[j];
        index_pos[j] = next_index;
        ret.push_back(perm1);
        // larger number change direction
        for (j = j + 1; j < N; j++)
            direction[j] = !direction[j];      
    }
    long ms = 1000*(clock() - start)/CLOCKS_PER_SEC;
    cout << "Generating "<< N <<" elements' full permutation using SJT Algorithm spends "<<ms <<" ms"<<endl;
    return ret;
}

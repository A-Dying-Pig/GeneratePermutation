#include "Permutation.hpp"

Permutation::Permutation(int n,PermutationType t):N(n),type(t)
{   
    if (N < 2)
        cout <<"ERROR! N = 0 or 1, Permutation needs 2 element at least"<<endl;
    max_index = 1;
    for (int i = 2; i <= N; i++){
        max_index *= i;
    }
    max_index --;
}


/* Convert a decimal number to corresponding value in ascending number system
 * @param val: decimal number
 * @param N: ascending number has N digits 
 * @return: corresponding value
 */
vector<int> decimal2ascending(long val, int N)
{
    vector<int> ret,radix;
    long current_radix = 1;
    bool found_largest_radix = false;
    //generating radix
    for (int i = 2; i <= N + 1; i++)
    {
        if(found_largest_radix){
            ret.push_back(0);
            continue;
        }
        if (current_radix <= val)
            radix.push_back(current_radix);
        else
        {
            found_largest_radix = true;
            ret.push_back(0);
        }
        current_radix *= i;
    }
    if(!found_largest_radix && current_radix <= val)
    {
        cout << "ERROR! N digits in ascending number are not enough to express val"<<endl;
        return ret;
    }
    //generate ascending number
    int qoutient = 0;
    for (vector<int>::reverse_iterator it = radix.rbegin(); it != radix.rend(); it++)
    {   
        qoutient = val / (*it);
        ret.push_back(qoutient);
        val -= qoutient * (*it);
    }
    return ret;    
}


/* Convert a number in ascending number system to decimal value
 * @param val: ascending number
 * @return: decimal value
 */
long ascending2decimal(vector<int> val)
{
    long current_radix = 1,ret = 0;
    int len = val.size();
    for (int i = 0; i < len; i ++)
    {
        current_radix *= (i + 1);
        ret += val[len - 1 - i] * current_radix;
    }
    return ret;
}


/* Convert a decimal number to corresponding value in descending number system
 * @param val: decimal number
 * @param N: descending number has N digits 
 * @return: corresponding value
 */
vector<int> decimal2descending(long val, int N)
{
    vector<int> ret,radix;
    long current_radix = 1;
    bool found_largest_radix = false;
    //generating radix
    for (int i = N + 1; i > 1; i--)
    {
        if(found_largest_radix){
            ret.push_back(0);
            continue;
        }
        if (current_radix <= val)
            radix.push_back(current_radix);
        else
        {
            found_largest_radix = true;
            ret.push_back(0);
        }
        current_radix *= i;
    }
    if(!found_largest_radix && current_radix <= val)
    {
        cout << "ERROR! N digits in descending number are not enough to express val"<<endl;
        return ret;
    }
    //generate descending number
    int qoutient = 0;
    for (vector<int>::reverse_iterator it = radix.rbegin(); it != radix.rend(); it++)
    {   
        qoutient = val / (*it);
        ret.push_back(qoutient);
        val -= qoutient * (*it);
    }
    return ret;
}


/* Convert a number in descending number system to decimal value
 * @param val: descending number
 * @return: decimal value
 */
long descending2decimal(vector<int> val)
{
    int len = val.size();
    long ret = val[0];
    for(int i = 1; i < len; i++)
        ret = ret * (i+2) + val[i];
    return ret;
}


/* input/output for vector<int>*/
void output_vector(vector<int> val)
{
    for (vector<int>::iterator it = val.begin(); it != val.end(); it++)
        cout << (*it) << ' ';
    cout << endl;
}


vector<int> input_vector()
{
    vector<int> ret;
    int temp;
    cin >> temp;
    ret.push_back(temp);
    while (cin.get() != '\n')
    { 
        cin >> temp; 
        ret.push_back(temp);
    }
    return ret;
}
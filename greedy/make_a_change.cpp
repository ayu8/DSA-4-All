#include <bits/stdc++.h>
using namespace std;

vector<int> make_a_change(vector<int> denomination,int amount)
{
    vector<int> coinCount;
    vector<int>::iterator itr;
    
    for(itr=denomination.begin();itr!=denomination.end();itr++)
    {
        coinCount.push_back(amount/(*itr));                     //Counting how it will pay amount with available denomination
        amount %= (*itr);
    }
    
    return coinCount;                                           //Returning result
}
//Algorithm Link : https://www.log2base2.com/algorithms/greedy/greedy-algorithm.html

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> denomination,coinCount;
    vector<int>::iterator itr;
    int d,amount;
    cin>>d;
    while(d>0)                      //Storing different denomination until 0
    {
        denomination.push_back(d);
        cin>>d;
    }
    sort(denomination.begin(),denomination.end(),greater<int>());
    
    cout<<"Amount : ";
    cin>>amount;                    //Storing total amount
    
    for(itr=denomination.begin();itr!=denomination.end();itr++)
    {
        coinCount.push_back(amount/(*itr));                     //Counting how it will pay amount with available denomination
        amount %= (*itr);
    }
    
    for(int i=0;i<denomination.size();i++)
    {
        cout<<denomination[i]<<"\t"<<coinCount[i]<<endl;        //Printing result
    }
    return 0;
}

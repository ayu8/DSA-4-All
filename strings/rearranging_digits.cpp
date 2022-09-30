#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T, D, flag;
	string N;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
	    cin>>D;
	    cin>>N;
	    flag = 0;
	    for(int j=0;j<D;j++)
	    {
	        if(N[j]=='5' || N[j] == '0')
	        flag = 1;
	    }
	    if(flag == 1)
	    cout<<"Yes\n";
	    else
	    cout<<"No\n";
	}
	return 0;
}

//Question Link
//https://www.codechef.com/submit/DIGARR?tab=statement

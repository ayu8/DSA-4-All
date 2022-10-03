//bubble sort problem 
#include <bits/stdc++.h>

using namespace std;

int main()

{

int n;

cin>>n;

int arr1[n],arr2[n];

for(int i=0;i<n;i++)

cin>>arr1[i];

 

for(int i=0;i<n;i++)

cin>>arr2[i];

 

for (int i = 0; i < n-1; i++)

for (int j = 0; j < n-i-1; j++)

{

if (arr1[j] > arr1[j+1])

swap(arr1[j], arr1[j+1]);

if (arr2[j] > arr2[j+1])

swap(arr2[j], arr2[j+1]);

 

}

bool sahi=true;

for(int i=0;i<=n-1;i++)

{

if(arr1[i]<=arr2[i])

{

sahi=false;

break;

}

}

if(sahi)

cout<<"Yes"<<endl;

else

cout<<"No"<<endl;

 

 

 

return 0;

}


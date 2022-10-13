//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
   
class Solution{
public:
    int isBitSet(int x){

        int count=0;

        if(x==0)

       {

           return 0;

       }

       while(x)

       {

         int p=x%2;

         

         if(p==0)

         return 0;

        

          x=x/2;

         

       }

       

       return 1;

    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isBitSet(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends

<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v1={20,40,30,10};    // vector declared with some values
  
  v1.push_back(10);                // element pushed inside vector at end
  
  v1.pop_back();                   // last element removed
  
  int size=v1.size();              // returns size of vector v1
  cout<<"size of vector:"<<size<<endl;
  
  for(int i=0;i<size;i++){
    cout<<v1[i]<<" ";              //Print elements using index
  }
  
  cout<<endl;
  
  
  sort(v1.begin(),v1.end());       // sorts the vector
  
  vector<int> iterator :: it;      // Creating the iterator 
  
  for(it=v1.begin() ; it!=v1.end() ;it++){
    cout<<it<<" ";                 // Using iterator to iterate over the vector
  }
  
  cout<<endl;
  
  
  return 0;
}

//These are the commonly used there are other methods too.

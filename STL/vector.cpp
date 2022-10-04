<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v1={10,20,30,40};    // vector declared with some values
  
  v1.push_back(10);                // element pushed inside vector at end
  
  v1.pop_back();                   // last element removed
  
  int size=v1.size();              // returns size of vector v1
  cout<<"size of vector:"<<size<<endl;
  
  
  
  
  return 0;
}

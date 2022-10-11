  bool increasingTriplet(vector<int>& nums) {

        
        int  maxi = INT_MAX;
        int mini = INT_MAX;
        for(int i :nums){
            if(i<maxi)
                maxi = i;
              else if(maxi<i &&i<mini){
                  mini =i;
              }  
            else if(mini<i){
                return true;
            }
            
        }
        return false;
    }
    
    

// Question Link:
//https://leetcode.com/problems/increasing-triplet-subsequence/

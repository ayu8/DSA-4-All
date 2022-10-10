class Solution {
public:
    int jump(vector<int>& nums) {
         int jump= 0;
     int  pos=0;
     int des =0;
      int n = nums.size();
      for(int i =0;i<n-1;i++){
          des= max(des,nums[i]+i);
          
          if(pos==i){
              pos = des;
              jump++;
          }
        
          
      }
      return jump;
    }
};

// question link:
//  https://leetcode.com/problems/jump-game-ii/

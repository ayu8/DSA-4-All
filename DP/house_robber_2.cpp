//recusive approach......

// class Solution {
// public:
//     int maxrob(vector<int>& nums,int n,int currentidx){
//         if(currentidx>=n){
//             return 0;
//         }
//         int lotenge=nums[currentidx]+maxrob(nums,n,currentidx+2);
//         int nhilotenge=maxrob(nums,n,currentidx+1);
//         return max(lotenge,nhilotenge);
// }
    
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1){
//             return nums[0];
//         }
//         int first = maxrob(nums,n-1,0);
//         int second = maxrob(nums,n,1);

//        return max(first,second);
        
//     }
// };


//memoization approach.......//

class Solution {
public:
    int maxrob(vector<int>& nums,int n,int currentidx,unordered_map<int,int>&mp){
        if(currentidx>=n){
            return 0;
        }
        int currentkey=currentidx;
        if(mp.find(currentidx)!=mp.end()){
            return mp[currentidx];
        }
        int lotenge=nums[currentidx]+maxrob(nums,n,currentidx+2,mp);
        int nhilotenge=maxrob(nums,n,currentidx+1,mp);
        mp[currentidx]= max(lotenge,nhilotenge);
        return mp[currentidx];
}
    
    int rob(vector<int>& nums) {
        unordered_map<int,int>mp,mp1;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int first = maxrob(nums,n-1,0,mp);
        int second = maxrob(nums,n,1,mp1);

       return max(first,second);
        
    }
};



//problems link:https://leetcode.com/problems/house-robber-ii/

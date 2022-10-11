//recusive code approach..........//

// #include<bits/stdc++.h>
// using namespace std;
// int frogcost(vector<int>&nums,int currentidx){
// 	if(currentidx==nums.size()-1){
// 		return 0;
// 	}
//   //if current index out of the bound then return max vlaue.....

// 	if(currentidx>nums.size()-1){
// 		return 10001;
// 	}
//   //recusive call.......
// 	int onejump=frogcost(nums,currentidx+1)+abs(nums[currentidx]-nums[currentidx+1]);
// 	int twojump=frogcost(nums,currentidx+2)+abs(nums[currentidx]-nums[currentidx+2]);
// 	return min(onejump,twojump);
// }


//memoization approach.....//

#include <bits/stdc++.h>
using namespace std;
int frogJumpk(int currentindex,vector<int> &v,int k,unordered_map<int,int> &mp){
  // cheking the base condition.......
    if(currentindex==v.size()-1){
        return 0;
    }
    if(currentindex>v.size()-1){
        return INT_MAX;
    }
  //check  in the map if allready visted or not if visted then no need to recusive call// 
    int currentkey = currentindex;
    if(mp.find(currentkey)!=mp.end()){
        return mp[currentkey];
    }
  
  
  //problem link:https://atcoder.jp/contests/dp/tasks/dp_a

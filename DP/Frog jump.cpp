//recusive code approach..........//

#include<bits/stdc++.h>
using namespace std;
int frogcost(vector<int>&nums,int currentidx){
	if(currentidx==nums.size()-1){
		return 0;
	}
  //if current index out of the bound then return max vlaue.....
  
	if(currentidx>nums.size()-1){
		return 10001;
	}
  //recusive call.......
	int onejump=frogcost(nums,currentidx+1)+abs(nums[currentidx]-nums[currentidx+1]);
	int twojump=frogcost(nums,currentidx+2)+abs(nums[currentidx]-nums[currentidx+2]);
	return min(onejump,twojump);
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<nums.size();i++)
		cin>>nums[i];
	
	int cost=frogcost(nums,0);
	cout<<cost;
}





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
    int ans = INT_MAX;
    for(int i=1;i<=k;i++){
        if(currentindex+i <= v.size()-1){
            int jump = frogJumpk(currentindex+i,v,k,mp) + abs(v[currentindex]-v[currentindex+i]);
            ans = min(ans,jump);
            
        }
        
    }
    mp[currentkey] = ans;
    return mp[currentkey];
}
int main() {
    
    int n,k;    cin>>n>>k;
    vector<int> v(n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)    cin>>v[i];
    int final = frogJumpk(0,v,k,mp);
    cout<<final;
    return 0;
}


//question link:https://atcoder.jp/contests/dp/tasks/dp_a



// Problem Link: https://leetcode.com/problems/counting-bits/

class Solution {
public:
    int one(int n){
        int ans=0;
        while(n!=0){
            ans+= n&1;
            n=n>>1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> bitone;
        for(int i=0;i<=n;i++){
            bitone.push_back(one(i));
        }
        return bitone;
    }
};
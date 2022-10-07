//problem link: https://leetcode.com/problems/hamming-distance/description/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        x=x^y;
        while(x!=0){
            ans+= x&1;
            x=x>>1;
        }
        return ans;
    }
};

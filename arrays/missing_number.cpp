class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumTilln = 0, sum = 0;
        for(int i=0;i<=nums.size();i++)
            sumTilln += i;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        return sumTilln-sum;
    }
};

// question link:
// https://leetcode.com/problems/missing-number/

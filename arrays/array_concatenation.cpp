class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> conc;
        int x=0;
        for(int i=0;i<(2*nums.size());i++)
        {
            conc.push_back(nums[x]);
            if(i==nums.size()-1)
                x=0;
            else
                x++;
        }
        return conc;
    }
};

//Question Link:
//https://leetcode.com/problems/concatenation-of-array/

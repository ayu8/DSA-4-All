class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int start = 0;
        int end = nums.size();
        while(start < end)
        {
            if(nums[start] > 0 && nums[start] < end)
            {
                int index = nums[start] - 1;
                if(nums[start] != nums[index])
                {
                    int temp = nums[start];
                    nums[start] = nums[index];
                    nums[index] = temp;
                }
                else
                    start++;
            }
            else
                start++;
        } 
        for(int i = 0; i < end; i++)
        {
            if(nums[i] != i + 1)
            {
                return i+1;
            }
        }
        return nums.size() + 1;
    }
};

// Leetcode
// https://leetcode.com/problems/first-missing-positive/
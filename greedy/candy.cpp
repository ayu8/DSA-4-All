// Link: https://leetcode.com/problems/candy/
// Difficulty : Hard

// Approach 2 Greedy
class Solution {
public:
    int candy(vector<int>& rat) {
    int n = rat.size(), sum = 0;
        vector<int> res(n, 1);  // initialize the resultant array with all elements 1 since each child will get minimum 1 candy
        
        if (n == 1) 
        {
            return 1;
        }
        
        // traverse the given ratings array and if the value of rat[i + 1] is greater than rat[i],
        // then update the value of ans[i + 1] as ans[i] + 1
        // this is to make sure higher rating one gets more than right neighbour
        for(int i=0; i<n-1; i++)
        {
            if (rat[i+1] > rat[i]) 
            {
                res[i+1] = res[i] + 1;
            }
        }
        
        // traverse the given array from the back and if the value of rat[i] > rat[i + 1] and the value of res[i] <= res[i + 1],
        // then update the value of res[i] as res[i + 1] + 1
        // this is to make sure higher rating one gets more than left neighbour
        for (int i=n-2; i>=0; i--) 
        {
            if (rat[i] > rat[i+1] && res[i] <= res[i+1]) 
            {
                res[i] = res[i+1]+1;
            }
        
            sum += res[i]; // increment the sum by res[i]
        }
        
        sum += res[n-1]; // increment with last element as it was left earlier
        
        return sum; // return the resultant sum
    }
};

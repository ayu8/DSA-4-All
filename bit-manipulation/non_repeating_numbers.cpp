    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here
        vector<int> res;
        
        int r=0;
        for (int i=0; i<nums.size(); i++) {
            r = r^nums[i];
        }
        
        // now r is in a^b form
        
        // to find position of least significant set bit
        r = r & ~(r-1);
        
        int r1 = 0, r2 = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] & r) {
                r1 = r1^nums[i];
            } else {
                r2 = r2^nums[i];
            }
        }
        
        if (r1 > r2) {
            res.push_back(r2);
            res.push_back(r1);
        } else {
            res.push_back(r1);
            res.push_back(r2);
        }
        
        return res;
    }

// question link:
// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        map<int, int> umap;
        
        int currSum = 0, start = 0, end = -1;
        
        for (int i=0; i<n; i++) {
            currSum += arr[i];
            
            if (currSum == 0) {
                start = 0;
                end = i;
                return true;
            }
            
            if (umap.count(currSum)) {
                return true;
            }
            
            umap.insert({currSum, i});
        }
        
        if (end == -1) {
            return false;
        }
        
    }

// question link:
// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

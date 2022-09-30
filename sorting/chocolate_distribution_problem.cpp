    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        
        sort(a.begin(), a.end());
        
        long long ans = a[m-1] - a[0];
        for (int i=1; i<n-m+1; i++) {
            ans = min(ans, a[i+m-1] - a[i]);
        }
        
        return ans;
    }

// question link:
// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

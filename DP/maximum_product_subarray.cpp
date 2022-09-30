	long long maxProduct(vector<int> nums, int a) {
	    // Return early if input is empty
        if (a==0) return 0;
		
        long long best = INT_MIN;
        // Running products
        long long maxProd = 1;
        long long minProd = 1;
        
        for (long long n: nums) {
            if (n < 0) {
                // Swap max and min
                swap(maxProd, minProd);
            }
            // Reset to current value if smaller or larger than it
            // (intuitively means that we start considering a new sub-array)
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            // Update the best
            best = max(best, maxProd);
        }
        
        return best;
    
	}

// question link:
// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

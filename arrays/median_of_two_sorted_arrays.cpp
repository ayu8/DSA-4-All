double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> val;
        double res = 0;
        for(int i = 0; i < nums1.size(); i++) {
            val.push_back(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            val.push_back(nums2[i]);
        }
        sort(val.begin(), val.end());
        if(val.size() % 2 != 0) {
            return val[val.size()/2];
        } else {
            return (val[val.size()/2] + val[val.size()/2 - 1]) / 2.0;
        }
    }
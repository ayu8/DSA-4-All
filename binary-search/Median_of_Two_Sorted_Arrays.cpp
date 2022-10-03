// LeetCode problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *p;
        if(nums1.size()>nums2.size()){
            for(int i=0;i<nums2.size();i++){
                nums1.push_back(nums2[i]);
            }
            sort(nums1.begin(),nums1.end());
            double ans;
            int len = nums1.size();
            if(len%2==0){
                ans = double(nums1[len/2 - 1] + nums1[len/2])/(double)2;
            }
            else{
                ans=nums1[len/2];
            }
            return ans;
        }
        else{
            for(int i=0;i<nums1.size();i++){
                nums2.push_back(nums1[i]);
            }
            sort(nums2.begin(),nums2.end());
            double ans;
            int len = nums2.size();
            if(len%2==0){
                ans = double(nums2[len/2 - 1] + nums2[len/2])/(double)2;
            }
            else{
                ans=nums2[len/2];
            }
            return ans;
        }
        return 0;
    }
};
// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;

class Solution {
public:
    vector <int> countingSort(vector <int> v, int n) {
        map <int,int> f;
        for (auto i = v.begin(); i != v.end(); i++) {
            f[*i]++;
        }
        int i = 0;
        for (auto it : f) {
            int val = it.first;
            int ct = it.second;
            for (int j=0; j<ct; j++) {
                v[i++] = val;
            }
        }
        return v;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        nums = countingSort(nums, n);
        return nums[n-k];
    }
};
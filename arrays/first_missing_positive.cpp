// https://leetcode.com/problems/first-missing-positive/
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector <int> v(n,0);
        for (int i=0; i<n; i++)
        {
            if (nums[i] >=1 && nums[i] <= n)
                v[nums[i]-1]++;
        }

        for (int i=0; i<n; i++)
        {
            if (v[i] == 0) return i+1;
        }
        return n+1;
    }
};
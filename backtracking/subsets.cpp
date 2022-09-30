// my first backtracking question
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> v = {};
    void findSubsets(int n, vector <int> input, vector <int> output, int i) {
        //base case
        if (i==n) {
            v.push_back(output);
            return;
        }
        output.push_back(input[i]);
        findSubsets(n, input, output, i+1);
        
        // excluding the ith letter
        output.pop_back();
        findSubsets(n, input, output, i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector <int> output = {};
        findSubsets(n, nums, output, 0);
        return v;
    }
};

int main() 
{
    Solution s;
    vector <int> nums = {1, 2, 3};
    vector<vector<int>> v = s.subsets(nums);
    for (int i=0; i<v.size(); i++) {
        for (int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
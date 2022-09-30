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
        
        //creating output (going down the recursion tree)
        output.push_back(input[i]);
        findSubsets(n, input, output, i+1);
        
        //excluding the last value (going up the recursion tree)
        output.pop_back();
        findSubsets(n, input, output, i+1);
    }
    
    void removeDuplicatesVector() {
        for (int i=0; i<v.size(); i++) {
            for (int j=0; j<v.size(); j++) {
                if (i != j && v[i] == v[j]) {
                    v.erase(v.begin() + i);
                    i--;
                    j=0;
                }
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <int> output = {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        findSubsets(n, nums, output, 0);
        removeDuplicatesVector();
        return v;
    }
};

int main() 
{
    Solution s;
    vector <int> nums = {1,1,2,2};
    vector<vector<int>> ans = s.subsetsWithDup(nums);
    
    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
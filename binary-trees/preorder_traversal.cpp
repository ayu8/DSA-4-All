// use your own main function
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
private:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (!root) {
            return;
        }
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
};

int main() 
{
    

    return 0;
}
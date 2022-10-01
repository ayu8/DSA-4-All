// https://leetcode.com/problems/convert-bst-to-greater-tree/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
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
    vector <int> v;
    
    int greaterSum(vector <int> v, int val) {
        int n = v.size();
        int sum = 0;
        for (int i=0; i<n; i++) {
            if (v[i] >= val) {
                sum += v[i];
            }
        }
        
        return sum;
    }
    
    void inorderSetValues(TreeNode * root) {
        if (root) {
            inorderSetValues(root->left);
            root->val = greaterSum(v, root->val);
            inorderSetValues(root->right);
        }
    }
    
    void inorderSetVector(TreeNode* root) {
        if (root) {
            inorderSetVector(root->left);
            v.push_back(root->val);
            inorderSetVector(root->right);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        inorderSetVector(root);
        for (int i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        inorderSetValues(root);
        
        return root;
    }
};
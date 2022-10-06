//using recursive code..............//

class Solution {
public:
    void totalleaf(TreeNode* root,string currentstring,int *ans){
        if(root->left==NULL && root->right==NULL){    //just check the condition
            currentstring+=to_string(root->val);   //then we reached the leaf node then we will add that node to cureent string after convertion int to string
            ans[0]+=stoi(currentstring,0,2);
            return;
        }
        string curr=to_string(root->val);  //just add every node value to a currstring and call recursivly left & right node
        if(root->left!=NULL){
            totalleaf(root->left,currentstring+curr,ans);
        }
        if(root->right!=NULL){
            totalleaf(root->right,currentstring+curr,ans);
        }
    }
  
  //just calling to function sumof root to leaf in the main function//
    int sumRootToLeaf(TreeNode* root) {
        int* ans=new int[1];
        ans[0]=0;
        totalleaf(root,"",ans);
        return ans[0];
        
    }
};



//using itrative code..................//


class Solution {
public:
    int sumRootToLeaf(TreeNode* rt) {
        if(! rt) return 0;
        
        int ans = 0;
        stack<pair<TreeNode*,int>> st;
        st.push({rt,0});
        
        while(! st.empty()) {
            auto curp = st.top(); st.pop();
            TreeNode* cur = curp.first;
            int cur_val = curp.second;
            
            // Equivalent to left shift by 1 and then ORing by cur->val.
            cur_val = cur_val*2 + cur->val;
            
            if(!cur->left && !cur->right)
                ans += cur_val;
            
            if(cur->left) st.push({cur->left, cur_val});
            if(cur->right) st.push({cur->right, cur_val});
        }
        
        return ans;
      
      
    }
    
    
    problem link:https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

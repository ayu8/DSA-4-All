// Problem : Complete Binary Tree
// link : https://practice.geeksforgeeks.org/problems/complete-binary-tree/0


class Solution{
public:    
    bool isCompleteBT(Node* root){
        //code here
        queue<Node*> q;
        q.push(root);
        bool flag=0;
        
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            if(!curr)flag=1;
            else
            {
                if(flag)return 0;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return 1;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(!root or root->val == val) { return root;}
        
        stack<TreeNode*> mystack;
        mystack.push(root);
        while(!mystack.empty()) {
            root = mystack.top(); mystack.pop();            
            if(root->val == val) {return root;}
            else if(val < root->val and root->left) { mystack.push(root->left); }
            else if(val > root->val and root->right) { mystack.push(root->right); }
            else { return nullptr; }            
        }
        return nullptr;
        
        
    }
};
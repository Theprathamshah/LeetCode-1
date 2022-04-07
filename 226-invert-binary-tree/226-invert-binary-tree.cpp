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
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root) {return nullptr; }
        
        TreeNode* mynewRight = nullptr;
        if(root->left) {
            mynewRight = invertTree(root->left);
            
        }
        TreeNode* mynewLeft = nullptr;
        if(root->right) {
            mynewLeft = invertTree(root->right);            
        }
        
        root->left = mynewLeft;
        root->right = mynewRight;
        
        return root;
    }
};
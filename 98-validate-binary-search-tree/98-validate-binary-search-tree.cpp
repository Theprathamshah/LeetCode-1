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

private:
    bool isValidBSThelper(TreeNode* root, TreeNode* lo = nullptr, TreeNode* hi = nullptr) {
        
        if(!root) { return true; }      
        
        // Validate your bounds
        // As long as the bound exists, each node mush lie within that bound. 
        if(lo) {
           if(!(root->val > lo->val)) { return false; }
        }
        if(hi) {
           if(!(hi->val > root->val)) { return false; }
        }
        
        // Ensure all nodes in the left and right subtrees are within their bounds
        // For the left subtree, root becomes the upper bound
        // For the right subtree, root becomes the lower bound
        return isValidBSThelper(root->left, lo, root) and isValidBSThelper(root->right, root, hi);
    }
public:
    bool isValidBST(TreeNode* root) {        
        return isValidBSThelper(root);
    }
};
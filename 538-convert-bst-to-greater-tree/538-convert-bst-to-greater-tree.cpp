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


// 

class Solution {
private:
    
    int helper(TreeNode* root, int parentNewVal) {
        
        if(!root) {return parentNewVal;}
        
        int rightSum = helper(root->right, parentNewVal); // This is the sum of all my right children. And I know in a BST, this is going to be greater than me!
        
        root->val += rightSum;
        
        int leftSum = helper(root->left, root->val);
        
        return leftSum;
        
        
        
        
        
        
        
        
    }

    
    
public:
    TreeNode* convertBST(TreeNode* root) {
        
        int answer = helper(root, 0);
        
        return root;
        
    }
};
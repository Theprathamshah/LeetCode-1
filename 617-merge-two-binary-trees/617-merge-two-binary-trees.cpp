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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(!root1 and !root2) { return nullptr; }
        
        TreeNode* node = new TreeNode();
        
        node->val = (root1 == nullptr ? 0 : root1->val) + (root2 == nullptr ? 0 : root2->val);
        
        node->left = mergeTrees(root1 == nullptr ? nullptr : root1->left, root2 == nullptr ? nullptr : root2->left);
        node->right = mergeTrees(root1 == nullptr ? nullptr : root1->right, root2 == nullptr ? nullptr : root2->right);
        
        return node;
    }
};
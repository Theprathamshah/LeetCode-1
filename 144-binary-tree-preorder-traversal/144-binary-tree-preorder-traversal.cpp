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
    vector<int> _answer;
    
    void helper(TreeNode* root) {
        
        if(!root) { return;}
        
        // Insert root first
        _answer.push_back(root->val);
        // Insert left child after root
        helper(root->left);
        // Insert right child after left
        helper(root->right);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        helper(root);        
        return _answer;
    }
};

// root -> left -> right..?
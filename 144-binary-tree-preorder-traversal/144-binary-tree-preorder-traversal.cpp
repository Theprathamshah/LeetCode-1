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
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root) {
            vector<int> result = {};
            return result;
        }
        
        int val = root->val;
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        
        // Re-allocate space big enough for the children and yourself
        left.reserve(left.size() + right.size() + 1);
        
        // Insert val before left
        left.insert(left.begin() ,val);
        // Insert right after left
        left.insert(left.end(), right.begin(), right.end());
        
        // root -> left -> right
        
        return left;
        
    }
};

// root -> left -> right..?
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
    struct Info {
        bool isbalanced;
        int height;
    };
    Info helper(TreeNode* root) {
        
        Info info{true, 0};
        if(!root) { return info; }
        
        Info left = helper(root->left);
        Info right = helper(root->right);
        
        info.height = max(left.height, right.height) + 1;
        info.isbalanced = (abs(left.height - right.height) > 1 ? false : true) and left.isbalanced and right.isbalanced;            
        return info;        
    }
    
public:
    bool isBalanced(TreeNode* root) {
        Info answer = helper(root);
        
        return answer.isbalanced;
    }
};
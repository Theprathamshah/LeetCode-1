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
    int closestValue(TreeNode* root, double target) {
        
        if(!root) { return INT_MAX; }
        int leftClosestValue = closestValue(root->left, target);
        int rightClosestValue = closestValue(root->right, target);
        
        int closestValue = leftClosestValue;
        if (abs(closestValue - target) > abs(rightClosestValue - target)) {
            closestValue = rightClosestValue;
        }
        if (abs(closestValue - target) > abs(root->val - target)) {
            closestValue = root->val;
        }
        return closestValue;
    }
};
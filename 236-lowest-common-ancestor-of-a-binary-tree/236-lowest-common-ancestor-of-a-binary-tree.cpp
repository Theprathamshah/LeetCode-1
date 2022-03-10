/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root) { return nullptr; }
        
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
        
        if (leftLCA!=nullptr && rightLCA!=nullptr) { // means one of my child tree matches with p and other with q.. so node is the LCA        
            return root; 
        }
        
        TreeNode* answer = (root->val == p->val) or (root->val == q->val) ? root : nullptr;
        
        if ((leftLCA || rightLCA) and answer) { // either or my left/right has p/q.. and i have q/p.. so again i am the LCA        
            return root;
        }
        
        // in all other cases, i should see whatever matched and send that as a LCA
        if(leftLCA) { return leftLCA; }
        if(rightLCA) { return rightLCA; } 
        
        return answer;
    }
};
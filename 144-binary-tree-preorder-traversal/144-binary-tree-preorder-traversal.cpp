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
        
        vector<int> answer;
        if(!root) {
            return answer;
        }
        
        stack<TreeNode*> mystack;
        
        mystack.push(root);
        
        while(!mystack.empty()) {
            
            root = mystack.top(); mystack.pop();
            
            //Go right
            if(root->right) {
                mystack.push(root->right);
            }
            
            //Go left
            if(root->left) {
                mystack.push(root->left);
            }
            
            
            // Add root to the answer
            answer.push_back(root->val);
        }
        return answer;
    }
};
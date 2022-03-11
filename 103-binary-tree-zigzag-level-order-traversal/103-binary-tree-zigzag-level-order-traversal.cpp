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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> answer = {};
        if(!root) { return answer; }
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true;
                
        while(!q.empty()) {
            
            vector<int> level(q.size());
            
            for(int idx = 0; idx < level.size(); idx++) {
                root = q.front(); q.pop();
                if(root->left) { q.push(root->left); }
                if(root->right) { q.push(root->right); }                
                level[idx] = root->val;                
            }
            if(leftToRight) {
                leftToRight = false; 
            }
            else
            {
                reverse(level.begin(), level.end()); leftToRight = true;
            }
           
            answer.push_back(level);
        }
        return answer;
    }
};
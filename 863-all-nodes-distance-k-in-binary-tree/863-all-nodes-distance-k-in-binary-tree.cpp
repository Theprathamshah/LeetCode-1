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
    
private:
    bool dfs(TreeNode* root, TreeNode* target) {
        if(!root) {return false; }
        
        if(root->val == target->val) {
            _path.push(root); 
            return true;            
        }
        
        // Add this node
        _path.push(root);        
        
        bool isPath = dfs(root->left, target);
        if(isPath) {
            return true;
        }
        isPath = dfs(root->right, target);
        if(isPath) {
            return true;
        }
        
        //Remove this node as this is not in the path
        _path.pop();
        
        return false;
    }
    stack<TreeNode*> _path;
    vector<int> _distance;

    void kDown(TreeNode* root, int k, TreeNode* blocking) {
        
        if (!root or root == blocking or k < 0) {return;}
        
        if(k == 0) {
            _distance.push_back(root->val);
            return;
        }
        
        kDown(root->left, k-1, blocking);
        kDown(root->right, k-1, blocking);
        
        return;

    }
    
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target); 
        
        //_path will be populated at this time
        
        
        TreeNode* blocking = nullptr;
        TreeNode* current = nullptr;
        while(!_path.empty()) {
            
            current = _path.top(); _path.pop();            
            kDown(current, k, blocking);            
            blocking = current;    
            k--;
        }
        
        return _distance;
        
    }
};
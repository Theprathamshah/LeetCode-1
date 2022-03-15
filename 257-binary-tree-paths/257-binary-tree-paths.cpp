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
    vector<string> _paths;
    
    void helper(TreeNode* root, string path = "") {
        
        if(!root->left and !root->right) { // At a leaf node
            path += to_string(root->val); // add the last element
            _paths.push_back(path); // push to the vector
            return;
        }
        
        path += to_string(root->val) + "->";
        
        if(root->left){
            helper(root->left, path);
        }
        if(root->right){
            helper(root->right, path);
        }
        
        
    }
   
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        _paths = {};
        if(root) { 
            helper(root);
        }
        
        return _paths;
    }
};
    
/*

vector<string> left = binaryTreePaths(root->left) // 2->5





*/
/*

Rought Notes
-----------------

if am not a part.. i will pass on my child who is a part.. obviously if i am not a part, only only of my children can be a aprt..

if I am a part of the solution.. i will return myself.. 

this will run in post order..

*/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {        
        if(!root) {return nullptr; }          
        
        root->left =  trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
         
        if (root->val < low) { // I will excuse myself and send my right child's info as it might have the answe.            
            return root->right;            
        }
        else if(root->val > high ) {  // I will excuse myself and send my left child's info as it might have the answe.
            return root->left;
        }
        else { 
            return root;
        }
    }
};

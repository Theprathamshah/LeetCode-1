/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
private:
    ListNode* _h;
    bool helper(ListNode* root) {
        
        if(!root) { return true; }
        
        bool res = helper(root->next);
        if(!res) { return false; }       
        if(root->val != _h->val) { return false; }
        _h = _h->next;
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        _h = head;
        return helper(head);

    }
};
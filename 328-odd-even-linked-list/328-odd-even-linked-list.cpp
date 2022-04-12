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
    void addOne(ListNode* &h, ListNode* &t, ListNode *n) {
        
        if(h == nullptr) {
            h = n;
            t = n;
            return;
        }
        
        // Add node to the end
        t->next = n;
        
        // Update tail
        t = n;
        
        return;   
    }
    
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head or !head->next) { return head; }
        
        ListNode *oh=nullptr, *ot=nullptr, *eh=nullptr, *et=nullptr; 
        ListNode *curr = head;
        ListNode *fwd = head->next;
        
        int counter = 1;
        while(curr) {
            
            // save next node
            fwd = curr->next;
            
            //Disconnect curr from the original list
            curr->next = nullptr;
            
            // Depending on the value. Add to the even list or the odd list
            if(counter++ & 1) {
                addOne(oh,ot,curr);
            }
            else {
                addOne(eh,et,curr);
            }
            
            // Move cur by 1
            curr = fwd;
        }
                
        
        ot->next = eh;
        return oh;
        
    }
};
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
    void addFirst(ListNode* &head, ListNode* &tail, ListNode* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        }
        node->next = head;        
        head = node;
        return;       
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head and !head->next) {return head; }
        

        ListNode* lo = nullptr;
        ListNode* hi = nullptr;
        ListNode* prevLo = nullptr;
        ListNode* fwdHi = nullptr;
        
        // ListNode* dummy = new ListNode(-1);
        // dummy->next = head;
        
        ListNode* prev = nullptr;        
        ListNode* curr = head;        
        
        int counter = 1;
        while(curr) {
                       
            if(counter == left) {
                prevLo = prev;      
                lo = curr;
            }
            if(counter == right) {
                fwdHi = curr->next;
                hi = curr;
                break;
            }     
            
            //Move curr and pre by 1
            prev = curr;
            curr = curr->next;
            counter++;
        }
        
        // Revese b/w hi and lo
        ListNode* tempHead = nullptr;
        ListNode* tempTail = nullptr;
        ListNode* node = nullptr;
        while(lo != fwdHi) {
            
            // save next
            node = lo->next;
            
            lo->next = nullptr;
            
            addFirst(tempHead, tempTail, lo);
            
            // move lo
            lo = node;            
        }
        
        tempTail->next = fwdHi;
        
        if(prevLo) {
            prevLo->next = tempHead;
            return head;            
        }
        else{ 
            return tempHead;
        }
    }
};
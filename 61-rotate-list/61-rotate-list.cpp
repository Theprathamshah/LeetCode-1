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
    ListNode* getKfromEnd(ListNode* head, int k) {
        
        if(!head or !head->next) { return head; }
        
        ListNode* f = head;
        ListNode* s = head;
        
        while(k-- and f) {
            f = f->next;
        }
        
        while(f) {
            f = f->next;
            s = s->next;
        }
        return s;
    }
    ListNode* getTail(ListNode* head) {
        if(!head or !head->next) { return head; }
        
        while(head->next) {
            head = head->next;
        }
        return head;
    }
    
    int KinBounds(ListNode* head, int k) {
        if(!head) { return 0; }
        
        int n = 1;
        while(head->next) {
            head = head->next;
            n++;
        }
        
        
        return  k% n;
    }
    
    
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        
        
        k = KinBounds(head, k);
        if(!head or !head->next or !k) { return head; }
        ListNode* newHeadPrev = getKfromEnd(head, k + 1);
        ListNode* tail = getTail(head);
        
        
        
        ListNode* newHead = newHeadPrev -> next;
        newHeadPrev -> next = nullptr;
        
        tail->next = head;
        
        return newHead;
        
        
        
    }
};
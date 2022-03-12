/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    
private:
    unordered_map<Node*, Node*> _visited;
    Node* getClonedNode(Node* oldNode) {
        if (oldNode == NULL) { return NULL; }
        
        if (_visited.count(oldNode) == 0) {
            _visited[oldNode] = new Node(oldNode->val);            
        }
        
        return _visited[oldNode];        
    }
public:
    Node* copyRandomList(Node* head) {
        
        if (head == NULL) { return NULL; }
        
        Node* newHead = new Node(head->val);
        
        _visited[head] = newHead;
        
        Node* current = head;
        Node* newCurrent = NULL;
        
        while(current != NULL) {
            
            newCurrent = getClonedNode(current);
            newCurrent->next = getClonedNode(current->next);
            newCurrent->random = getClonedNode(current->random);
            
            current = current->next;            
        }
        
        return newHead;        
    }
};
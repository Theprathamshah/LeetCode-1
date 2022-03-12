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
    unordered_map<Node*, Node*> _visited; // Track oldNode -> newNode maping
	
	/*  -------------------------------------------------	
	 *   Input: Pointer to a node in the original list        
	 *   Output: Pointer to a node in the cloned list	  
	 * -------------------------------------------------  */	 
    Node* getClonedNode(Node* oldNode) {
        if (oldNode == NULL) { return NULL; }
        
        if (_visited.count(oldNode) == 0) 
        { 
		    // If the node has not been visited, then create a node which will belong to the cloned list
            _visited[oldNode] = new Node(oldNode->val);            
        }        
        return _visited[oldNode];        
    }
public:
    Node* copyRandomList(Node* head) {
        
        if (head == NULL) { return NULL; }
       
        Node* current = head;
        Node* newCurrent = NULL;
        
        while(current != NULL) { // Iterative over the original list
            
            // Get the cloned node beloning to the cloned list
			newCurrent = getClonedNode(current);
			
			// Update the next and random pointers
            newCurrent->next = getClonedNode(current->next);
            newCurrent->random = getClonedNode(current->random);
            
            // Go to the next node
			current = current->next;            
        }
        
        return _visited[head];        
    }
};
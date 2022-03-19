class FreqStack {
    
private:
    
    int pos;
    priority_queue<pair<int, pair<int, int>>> pq; // <freq, <pos, val>>. Values will be arranged in such a way that the value with the highest count will be on the top. When two or more elements have the same count, then the element with has the higher pos will be on top. Unfortuntely, the push and pop will not be in O(1)
        
    unordered_map<int,int> freq; // <val, freq>
    
    
    
    
    
public:
    FreqStack() {
        pos = 0;        
    }
    
    void push(int val) { // O(logN)
        pq.push(make_pair(++freq[val],make_pair(++pos, val)));
        }
    
    int pop() { // O(logN)
        
        pair<int, pair<int, int>> res = pq.top(); pq.pop();  // it is guaranteed that there will be at least one element in the stack before calling pop.
        
        int val = res.second.second;
        
        --freq[val];
        
        return val;
        
        
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
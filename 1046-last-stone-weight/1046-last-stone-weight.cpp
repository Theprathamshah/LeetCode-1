class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
       // Max HEAP
        priority_queue<int> pq;
        for(auto& stone : stones) {
            pq.push(stone);
        }
        
        // 1. pop top two elements
        // 2. Substract
        // 3. inssert in the pq
        // 4. Repeat until the size is 1
        
        while(pq.size() > 1) {
            int h1 = pq.top(); pq.pop();
            int h2 = pq.top(); pq.pop();
            pq.push(h1-h2);
        }
        int answer = pq.top(); pq.pop();
        return answer;
        
    }
};
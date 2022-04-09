class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {     
        
        // Create a "freq" map
        // O(1) time
        // O(n) space i think (?)
        unordered_map<int, int> freq; 
        for (auto& n : nums) {
            freq[n]++;
        }

        // Insert pair of <count, val> into the min_heap. push() time in a heap is O(NlogN)
        // we will keep this set of size "k". Everything we will go past size "k", we will pop the min eleemnt.. pop will be in O(1)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (auto& [val, count] : freq) {            
            pq.push(make_pair(count, val));            
            if (pq.size() > k) { // throw out the 1st element as it might have the least count
                pq.pop();
            }            
        }
        
        // once we have iterated over the freq map, then we need to iterate over the set from the back (largest will be at the back) and add to the answer.
        // then we can remove that last elment and keep repeating this process until the set is empty
        vector<int> ans;
        while(!pq.empty()) {            
            ans.push_back(pq.top().second); // first -> count, second -> val
            pq.pop();
        }        
        
        // The question is asking top K (in any order) so we can return ans.. if it was asking in the order of greatest to smallest, then we needed to reverse the vector
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};
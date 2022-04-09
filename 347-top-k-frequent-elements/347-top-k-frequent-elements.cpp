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

        // Insert pair of <count, val> into the set which will be arranged in ascending order
        // we will keep this set of size "k"
        set<pair<int,int>> s;
        for (auto& [val, count] : freq) {            
            s.insert(make_pair(count, val));
            if (s.size() > k) { // throw out the 1st element as it might have the least count
                s.erase(s.begin());
            }            
        }
        
        // once we have iterated over the freq map, then we need to iterate over the set from the back (largest will be at the back) and add to the answer.
        // then we can remove that last elment and keep repeating this process until the set is empty
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.rbegin()->second); // first -> count, second -> val
            s.erase(*s.rbegin());
        }        
        return ans;        
    }
};
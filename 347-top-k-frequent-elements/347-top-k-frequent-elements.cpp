class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {     
        
        // Create a "freq" map
        unordered_map<int, int> freq; 
        for (auto& n : nums) {
            freq[n]++;
        }
        
        /*
        1 -> 3
        2 -> 3
        3 -> 1
        
        */
        
        set<pair<int,int>> s;
        for (auto& [val, count] : freq) {            
            s.insert(make_pair(count, val));
            if (s.size() > k) {
                s.erase(s.begin());
            }            
        }
        
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.rbegin()->second);
            s.erase(*s.rbegin());
        }
        
        
        return ans;
        
        
        
        
        
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, bool> seen; // number and seen
        
        for (auto& num : nums) {
            if(seen.count(num)) {
                return true;
            }
            seen[num] = true;
        }
        return false;
    }
};

/*
Givem:
 - any number can appear in the array (+ve / -ve)
 - therefore, we cant do the index to freq mapping
 
 we can se a simple unordered_map


















*/
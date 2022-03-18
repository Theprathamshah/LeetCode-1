class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result = 0;
        for (auto& num : nums) {            
            result ^= num;            
        }
        
        //  every element appears twice will be zeroed above.
        // result will store just the number which doesnt appear tweice
        
        return result;
        
    }
};

/*

XOR everything

010
010
----


000
010
---
010
010

001










*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> map;
        for(auto&num : nums) {
            if(map.count(num) > 0) {
                return true;
            }
            map[num] = true;
        }
        return false;
    }
};

/*

-109 <= nums[i] <= 109
1 <= nums.length <= 105

a simle soln is using a hashmap..







*/
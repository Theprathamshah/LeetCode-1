class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // int answer = 0; //xor everything. Everything will cancel out with each other.. only the non-dulicate will remain        
        // for (auto&n: nums) {
        //     answer ^= n;
        // }
        // return answer;
        
        return accumulate(nums.begin(), nums.end(), 0, [](int x, int y){ return x^y; });
    }
};
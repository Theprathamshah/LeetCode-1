class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        
        // Definations
        int sumOfProducts = 0;
        
        vector<vector<int>> map(100, vector<int>()); // so this takes up space.. and is not constant..
        
        
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(), greater<int>());
        
        for(int i=0; i < nums1.size(); i++) {
            sumOfProducts += nums1[i] * nums2[i];
        }
        
        return sumOfProducts;
    }
};

/*
to minimize, we need to pair the largest in num1 with the smallest in num2..


.......... now the question is what is the best way to accomplish this task...? ...............

1. we can "create" heap and all but that's insanly slow operation.. i mean its similar to sorting both of them right.. NlogN time

2. I tried sorting them inplace.. and thats so much faster in terms of time and space..  however, the question says we can touch nums2..

now clearly.. i need to do something inplace in nums1......... i think i might swapping the values so i dont loose it..


[4] <-- let's say if i have the freq map.. i can 


*/
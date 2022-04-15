class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        
        // Definations
        int sumOfProducts = 0;
        
        
        
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
now the question is what is the best way to accomplish this task...? 




we can create heap and all but that's insanly slow operation.. i mean its similar to sorting both of them right.. NlogN time






*/
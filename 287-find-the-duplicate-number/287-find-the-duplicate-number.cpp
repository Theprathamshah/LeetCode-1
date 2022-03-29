class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        auto isPresent = vector<bool>(nums.size(), false);
                
        for (auto& num: nums) {
            
            if(isPresent[num-1] == true) {
                return num;
            }
            isPresent[num-1] = true;            
        }
        return -1;
    }
};

/*
 [1,3,4,2,2]
 
 n+1 integers... 6 integers..
 
 n is [1,5].... but 1 number is repeating.. it could be any one of  to 5.. 
 
 2,3,4,5,5
 
 so lets say.. if 1 is present.. we will make index 0 as -ve
 
 i = 0, num[0] = 1.. which is +ve, make idx 1-1 as -ve
 i = 1, num[0] = 1.. which is +ve, make idx 1-1 as -ve
 
 

 










*/
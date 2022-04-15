class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        
        // Definations
        int sumOfProducts = 0;
        priority_queue<pair<int,int>> pq_2_max;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq_1_min;
        
        // Populate pq  - insertion time O(nlogn)                
        for(int i = 0; i < nums1.size(); i++) {           
            pq_1_min.push(make_pair(nums1[i],i));
            pq_2_max.push(make_pair(nums2[i],i));            
        }
        
        // Rearrage num1        
        for(int i = 0; i < nums1.size(); i++) {           
            
            auto [val1, idx1] = pq_1_min.top(); pq_1_min.pop();
            auto [val2, idx2] = pq_2_max.top(); pq_2_max.pop();            
            nums1[idx2] = val1;
            sumOfProducts += val1*val2;
        }
        
        
        
        return sumOfProducts;
    }
};

/*
to minimize, we need to pair the largest in num1 with the smallest in num2..


now the question is what is the best way to accomplish this task...? 

we can create 2 heaps.. max heap (value and index in num2) and min heap (vale and index in num1)

pop from max heap.. look at the index in num2... move the val1 from idx1 to this new idx..

we can run the make_heap command on both arrays to convert them into heap... and iterate over them i guesss?







*/
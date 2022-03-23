class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int steps = 0;
        while(target > startValue){
            if(target & 1) {
                target++;                 
            }
            else
            {
                target >>= 1;                               
            }
            steps++;
        }
              
        
        return steps + startValue - target;
    }
};

/*


(target + 2)/2 (3 steps) is same as target/2 + 1 (2 steps)
(target + 3)/2 (4 steps) is same as target+1/2 + 1  (2 steps)\\*/
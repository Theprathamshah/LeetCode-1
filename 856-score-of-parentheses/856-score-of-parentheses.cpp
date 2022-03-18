class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> sumAtVariousLevels;
        
        int sumAtLevel0 = 0; // this is the final answer
        
        int sumAtCurrentLevel = 0, sumAtPreviousLevel = 0;
        int currentSum = 0;        
        for (auto& bracket : s) {            
            if (bracket == '(') // start of a new level
            {
                currentSum = 0;
                sumAtVariousLevels.push(currentSum);                
            }
            else
            {                                        
                sumAtCurrentLevel = sumAtVariousLevels.top(); sumAtVariousLevels.pop();  
                if(sumAtCurrentLevel == 0)
                {
                    sumAtCurrentLevel += 1;                    
                }
                
                
                // However, the curent level is ending..
                if(sumAtVariousLevels.empty())
                {
                    sumAtLevel0 += sumAtCurrentLevel; // just add.. no factor of 2
                }
                else
                {
                    sumAtPreviousLevel = sumAtVariousLevels.top(); sumAtVariousLevels.pop();  
                    sumAtPreviousLevel += sumAtCurrentLevel * 2;                    
                    
                    sumAtVariousLevels.push(sumAtPreviousLevel);    
                }
                
            }

            
        }
        return sumAtLevel0;
    }
};
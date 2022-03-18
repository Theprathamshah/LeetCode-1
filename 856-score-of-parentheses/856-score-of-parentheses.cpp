
/*

DO AGAIN

*/



class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> sumAtVariousLevels;
        int sumAtLevelZero = 0;
        sumAtVariousLevels.push(sumAtLevelZero); // this is the final sum
               
        int sumAtCurrentLevel = 0, sumAtPreviousLevel = 0;                
        for (auto& bracket : s) {            
            
            if (bracket == '(') // start of a new level
            {                
                sumAtVariousLevels.push(0);                
            }
            else // end of current level
            {                                        
                sumAtCurrentLevel = sumAtVariousLevels.top(); sumAtVariousLevels.pop();                  
                sumAtPreviousLevel = sumAtVariousLevels.top(); sumAtVariousLevels.pop(); 
                
                sumAtPreviousLevel += max(2 * sumAtCurrentLevel, 1); // sumAtCurrentLevel == 0 means we had something like (). And in this case, we will add 1 to the previous level. On all other cases, it will be 2* sumAtCurrentLevel
                    
                sumAtVariousLevels.push(sumAtPreviousLevel);    
                }                
            }
        sumAtLevelZero = sumAtVariousLevels.top(); sumAtVariousLevels.pop();  
        return sumAtLevelZero;
    }
};
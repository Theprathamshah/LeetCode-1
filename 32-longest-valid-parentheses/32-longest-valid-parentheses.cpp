class Solution {
public:
    int longestValidParentheses(string s) {
                
        int openBracketCounter = 0;
        
        // Iterate from front and mark ')' with no matching open brackets
        for (int idx = 0; idx < s.size(); idx++) { // O(n)            
            if(s[idx] == ')') {
                if (openBracketCounter == 0) {
                    s[idx] = 'x'; 
                }
                else {
                    openBracketCounter--;
                }
            }
            else {
                openBracketCounter++ ;
            }        
        }
        
        // Iterate from back and mark '(' with no matching open brackets
        openBracketCounter = 0;
        for (int idx = s.size() - 1; idx >= 0; idx--) { // O(n)            
            if(s[idx] == '(') {
                if (openBracketCounter == 0) {
                    s[idx] = 'x'; 
                }
                else {
                    openBracketCounter--;
                }
            }
            else {
                openBracketCounter++;
            }        
        }
       
        
        // Now iterate another time and count pairs
        int maxCount = 0, runningCount = 0;
        for (auto& ch: s) { // O(n)
            
            if(ch == 'x') {
                runningCount = 0;
            }
            else if(ch == '(') {
                // do nothing
            }
            else {
                runningCount += 2;
                maxCount = max(maxCount, runningCount);
            }
        }
        return maxCount;
        
        
    }
};
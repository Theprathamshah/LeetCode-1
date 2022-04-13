class Solution {
public:
    int longestValidParentheses(string s) {
                
        stack<int> openBracketIndexHolder;
        
        // Iterate once to find the index of brackets with no matching and mark them as 'x'
        for (int idx = 0; idx < s.size(); idx++) { // O(n)
            
            if(s[idx] == ')') {
                if (openBracketIndexHolder.empty()) {
                    s[idx] = 'x'; // Mark ')' with no matching open brackets
                }
                else {
                    openBracketIndexHolder.pop();
                }
            }
            else {
                openBracketIndexHolder.push(idx); // save idx of open brackets
            }
        }
        
        while(!openBracketIndexHolder.empty()) {
            int idx = openBracketIndexHolder.top(); openBracketIndexHolder.pop();
            s[idx] = 'x';    // Mark '(' with no matching closing

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
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int runningCount = 0;
        int minRemove=0;
        
        string output;
        
        stack<int> mystack;
        
        for(int i = 0, j = 0; i < s.size(); i++) {
            
            if(s[i] == ')')
            {
                if (runningCount == 0)                {                    
                    continue;
                }
                else                {
                    runningCount--;
                }                
            }
            else if (s[i] == '(')
            {                               
                runningCount++;
                
                if (runningCount > 0)
                {
                    mystack.push(j); // push the index where we found an opening bracket
                    
                }
            }
            j++;
            output.push_back(s[i]);
            
        }
        
        // Now depending upon the runningCount, we can pop that many times
        
        int idx;
        while(runningCount)
        { 
            idx = mystack.top(); mystack.pop();
            
            output.erase(idx,1);
            runningCount--;
            
        }
        return output;        
    }
};

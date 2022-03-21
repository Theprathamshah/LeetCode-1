class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> lastSeen(26,-1);
        
        for(int i = 0; i < s.size(); i++) { lastSeen[s[i] - 'a'] = i; }
        
        vector<int> partitionLengths;
        int curLen = 0;
        
        int curStartIdx = 0, curEndIdx = 0;
        for(int i = 0; i < s.size(); i++)
        {
            curEndIdx = max(curEndIdx, lastSeen[s[i] - 'a']);
            
            if(i == curEndIdx) { // we have reached the end of the partition
                
                curLen = curEndIdx - curStartIdx + 1;
                partitionLengths.push_back(curLen);
                
                curStartIdx = i+1;
                curEndIdx = i+1;
                
            }
                
        }
        return partitionLengths;
            
    }
};
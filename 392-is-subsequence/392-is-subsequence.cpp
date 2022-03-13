class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        
        if(!s.size())  // means s was complete found.
        {
            return true;
            
        }
        if(!t.size()) // means we finished t but not s.. means not
        {
            return false;
            
        }
        bool ans;
        
        // lets just compare 1 character at a time
        if(s[0] == t[0])
        {
            ans = isSubsequence(s.substr(1), t.substr(1));            
        }
        else
        {
            ans = isSubsequence(s, t.substr(1));            
        }                              
        return ans;        
    }
};
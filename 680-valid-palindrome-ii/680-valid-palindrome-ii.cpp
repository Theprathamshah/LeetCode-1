class Solution {
private:
    bool helper(string& s, int l, int h, bool chanceLeft = true) {
        
        // Bas condition
        if (l >= h) {
            return true;
        }
        
        bool answer = false;
        if (s[l] == s[h]) 
        { // If the first and last characters match, we rely on recursion to get us the answer to the smaller problem

            answer |= helper(s,l+1,h-1,chanceLeft); 
        }
        else if (!chanceLeft) 
        { // If the first and last characters DON'T match, and we have no chance left, then we don't need to go any further and we can directly return false. 
            return false;
        }
        else 
        {   // If the first and last characters DON'T match, but we have a chance left, then we will explore both cases. Either one returns true, we are good!
            
            chanceLeft = false;                
            if (s[l+1] == s[h]) 
            { // CASE I - if moving first by 1 to the right and last match, then we will explore this branch
                answer |= helper(s, l+1, h, chanceLeft);
            }        
            if (s[l] == s[h-1]) 
            {  // CASE II - if moving last by 1 to the left and first match, then we will "ALSO" explore this branch
                answer |= helper(s, l, h-1, chanceLeft);
            }            
        }
        return answer;        
    }
public:
    bool validPalindrome(string s) {
        
        int l = 0;
        int h = s.size() - 1;
        
        return helper(s,l,h);
     }
};


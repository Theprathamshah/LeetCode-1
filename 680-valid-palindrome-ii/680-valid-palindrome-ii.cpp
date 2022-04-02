/*
High level idea

This is the same problem as a palindrome problem with one slight twist.

The twist is that, if at any point the lo and high characters don't match, we don't just give up. 

Instead, we give the string another attempt. Now, we have two options. 

Either we move low by 1 to the right keeping hi at the same place. And do the palindome check again.
Or we move high by 1 to the left keeping lo at the same place. And do the palindome check again. 

now the question is which option should we choose? the answer is, we should try both and if any of them gives the answer we are good..

now one caveat here. now there are no more chances left. if any of the characters don't match, we give up. as we already gave the string one chance.

*/


class Solution {
private:
    bool canPalindrome(string& s, int low, int high, bool chanceLeft = true) {
        
        bool answer = true;
        while (low < high) 
        {
            if (s[low] == s[high])
            { // if the string is a perfect palindrome, then we will keep comparing and at the end gracefully exit this loop
                
                low++; high--; 
            }  
            else if (!chanceLeft) 
            {
                answer = false;
                break;              
            }
            else // this means, th 
            {
                chanceLeft = false;
                answer = canPalindrome(s, low + 1, high, chanceLeft) || canPalindrome(s, low, high - 1, chanceLeft);    
                break;
            }
        }        
        return answer;            
    }
public:
    bool validPalindrome(string s) {        
        int low = 0;
        int high = s.size() - 1;        
        return canPalindrome(s,low,high);
     }
};
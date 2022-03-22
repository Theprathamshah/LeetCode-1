class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string answer(n,'a');
        k = k - n;
        int val;
        while(k > 0) {
            
            val = min(k,25);
            
            answer[--n] += val;
            k = k - val;
            
            
        }
        return answer;
        
    }
};
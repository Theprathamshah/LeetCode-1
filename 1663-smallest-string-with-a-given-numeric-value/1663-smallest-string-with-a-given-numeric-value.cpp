class Solution {
    
private:
    int maxPotential(int n) { return n * 26; }
public:
    string getSmallestString(int n, int k) {
        string answer = {};     
        int maxWithMinus1, maxValdWithA, excess;
        
        for (int i = 0; i < n; i++){
            
            // I want to select the Select 'a' always..
            // this is the max allowed remainder.
            // if the target is greater than maxAllowed, then we can choose a;
            maxWithMinus1 = maxPotential(n-i-1);
            maxValdWithA = maxWithMinus1 + 1;
            
            if (k > maxValdWithA) { // can't use a
                
                excess = k - maxWithMinus1;
                
                k -= excess;
                
                answer.push_back(excess - 1 + 'a');
                
            }
            else
            {
                k--;
                answer.push_back('a');
            }
        }
        
        
        
        return answer;
    }
    
};
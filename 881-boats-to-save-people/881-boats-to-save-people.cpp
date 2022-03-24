class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        // Sort in decending order
        sort(people.begin(), people.end(), greater<int>()); // O(NlogN)
        
        // Pick the largest and the 2nd largest..
        int bigIdx = 0;
        int smallIdx = people.size() - 1;
        
        int nBoats = 0;
        while(bigIdx <= smallIdx) {
            
            if ((people[bigIdx] + people[smallIdx] <= limit) and (bigIdx + 1 <= smallIdx)) {
                
                bigIdx++;  
                smallIdx--;
                
            }
            else if(people[bigIdx] <= limit)
            {
                bigIdx++;                
            }
            else { // people[smallIdx] <= limit
                smallIdx--;                
            }
            nBoats++;
        }
        return nBoats;
        
    }
};

/*

2 

*/
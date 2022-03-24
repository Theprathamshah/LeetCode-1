class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        // Sort in decending order
        sort(people.begin(), people.end()); // O(NlogN)
        
        // Pick the largest and the 2nd largest..
        int smallIdx  = 0;
        int bigIdx = people.size() - 1;
        
        int nBoats = 0;
        while(smallIdx <= bigIdx) {            
            if (people[smallIdx] + people[bigIdx] <= limit) {      // basically if i can't pair up a fat guy with a really lean guy then the fat guy needs a boat of his own          
                smallIdx++;
                
            }
            bigIdx--;                                  
            nBoats++;
        }
        return nBoats;
    }
};

/*

2 

*/
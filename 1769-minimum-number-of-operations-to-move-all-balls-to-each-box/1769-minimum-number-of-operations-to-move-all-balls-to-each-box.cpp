class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        
        vector<int> answer(n,0);
        
        for (int currIdx = 0; currIdx < n; currIdx++) {
            
            int totalMoves = 0;
            
            // Left traversal
            int runningCount = 1;            
            for (int leftIdx = currIdx - 1; leftIdx >= 0; leftIdx--) {
                if (boxes[leftIdx] == '1') {
                    totalMoves += runningCount;
                }
                runningCount++;                            
            }
            
            
            // Right traversal
            runningCount = 1;
            for (int rightIdx = currIdx + 1; rightIdx < n; rightIdx++) {
                if (boxes[rightIdx] == '1') {
                    totalMoves += runningCount;
                }
                runningCount++;                            
            }
            
            // Update total moves
            answer[currIdx] = totalMoves;
        }
        
        return answer;        
    }
};
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& sortedArr) {
        
        sort(sortedArr.begin(), sortedArr.end()); // O(NlogN)
        
        // find the minPositiveDelta
        int minPositiveDelta = INT_MAX;
        int tempDelta;
        for (int i = 1; i < sortedArr.size(); i++) { // O(N)
            tempDelta = sortedArr[i] - sortedArr[i-1];
            minPositiveDelta = min(minPositiveDelta, tempDelta);
        }
        
        vector<vector<int>> answer;
        vector<int> element;
        for (int i = 1; i < sortedArr.size(); i++) { // O(N)
            tempDelta = sortedArr[i] - sortedArr[i-1];
            if (tempDelta == minPositiveDelta) {
                // Save element
                element.emplace_back(sortedArr[i-1]); element.emplace_back(sortedArr[i]);
                
                // Update answer
                answer.emplace_back(element);
                
                //Clear element
                element.clear();                
            }            
        }
        return answer;
        
        
        
    }
};
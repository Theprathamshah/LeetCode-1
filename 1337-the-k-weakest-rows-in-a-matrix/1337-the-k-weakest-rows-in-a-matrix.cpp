
// typedef pair<int,int> pii; // <firstZero, rowIndex>

class Solution {
    
private:
    
        int firstZeroIdx(vector<vector<int>>& mat, int rowIndex) {        
        vector<int> row = mat[rowIndex];        
        auto it = lower_bound(row.begin(), row.end(), 0, greater<int>()); // this will return the iterator to the 1st zero in this vector
        
        // return [it - row.begin(), rowIndex];
        return it - row.begin();
        
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
                
        set<pair<int,int>> weakest; // smallest in the front..
        
        for(int rowIndex = 0; rowIndex < mat.size(); rowIndex++) {
            weakest.emplace(firstZeroIdx(mat, rowIndex),rowIndex); // emplace coz we can directly move whatever is returned into the answer..
            if(weakest.size() > k) { // we only want smallest k for the final answer...
                weakest.erase(--weakest.end()); //remove the last element
            }
        }
        
        vector<int> answer;
        
        // weakest will have k elements..
        for (auto& [irstZero, rowIndex] : weakest) {
            answer.push_back(rowIndex);
        }            
        return answer;
        
        
    }
};
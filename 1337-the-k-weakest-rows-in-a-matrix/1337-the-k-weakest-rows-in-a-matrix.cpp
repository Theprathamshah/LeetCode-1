class Solution {   
private:
       typedef pair<int,int> pii; // <firstZero, rowIndex>  
    
        pii firstZeroIdx(vector<vector<int>>& mat, int rowIndex) {        
        vector<int> row = mat[rowIndex];        
        auto it = lower_bound(row.begin(), row.end(), 0, greater<int>()); // this will return the iterator to the 1st zero in this vector
        
        return make_pair(it - row.begin(), rowIndex);        
        
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
                
//         set<pii> weakest; // smallest in the front..        
//         for(int rowIndex = 0; rowIndex < mat.size(); rowIndex++) {
//             weakest.emplace(firstZeroIdx(mat, rowIndex)); // emplace coz we can directly move whatever is returned into the answer..
//             if(weakest.size() > k) { // we only want smallest k for the final answer...
//                 weakest.erase(--weakest.end()); //remove the last element
//             }
//         }
//         vector<int> answer;        
//         // weakest will have k elements..
//         for (auto& [irstZero, rowIndex] : weakest) {
//             answer.push_back(rowIndex);
//         }
//         return answer;
        
        priority_queue<pii> weakest;
        for(int rowIndex = 0; rowIndex < mat.size(); rowIndex++) {
            weakest.push(firstZeroIdx(mat, rowIndex)); // emplace coz we can directly move whatever is returned into the answer..
            if(weakest.size() > k) { // we only want smallest k for the final answer...
                weakest.pop(); //remove the largest element
            }
        }
        
        vector<int> answer;        
        // weakest will have k elements..
        while(k--){
            answer.push_back(weakest.top().second); weakest.pop();
        } 
        
        reverse(answer.begin(), answer.end());        
        return answer;
        
        
    }
};
class Solution {
    
private:
    pair<int,int> IdxOfFirstZero(vector<vector<int>>& mat, int rIdx) {
               
        vector<int> row = mat[rIdx];     
        // find position of first 0 by binary search  
        auto first0 = lower_bound(row.begin(), row.end(), 0, greater<int>());       
        return make_pair(first0 - row.begin() , rIdx);               
    }
    
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        set<pair<int,int>> weakest; // pair < nOnes, rowIdx>. We insert into a set so the lowest nOnes are early in the set. When we pop, then the lowest ones will come out first..
        
        for (int rIdx = 0; rIdx < mat.size(); rIdx++) {
            weakest.insert(IdxOfFirstZero(mat, rIdx));
            if (weakest.size() > k) { // remove last item if exceeding size k
                weakest.erase(--weakest.end());  
            }  
        }
        
        vector<int> ans;
        for (int count = 0; count < k; count++) {
            ans.emplace_back(weakest.begin()->second);
            weakest.erase(weakest.begin());            
        }
        
        return ans;
        
    }
};

/*


n cols  -> for every row (r), binary serach to find the index (log n). 

    we can store (index, row_number) in a set or min_heap... (insertion in a set or min_heap is log(n) i guess..)
    
    then we pop.. k times to give minimum indices...

m rows -> sort in m log m



[1,1,0,0,0]




*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int M = matrix.size(); // 4
        if (M == 0)
            return false;
        int N = matrix[0].size(); // 3

        int start = 0;
        int end = M*N - 1; // 14
        
        int mid;
        int r,c;
        while(start<=end) {
            
            mid = start + (end - start) / 2;
            
            r = mid / N;
            c = mid % N;
            
            if(matrix[r][c] == target) {return true; }
            else if (matrix[r][c] < target) { // start is mid+1;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            
        }
        return false;
    }
};

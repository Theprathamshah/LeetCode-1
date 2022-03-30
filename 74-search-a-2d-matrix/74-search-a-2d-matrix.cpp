class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int rowIdx = 0;
        int colIdx = cols - 1;
        while(colIdx > -1 and rowIdx < rows) {
            
            if(matrix[rowIdx][colIdx] == target) { return true; }
            else if(matrix[rowIdx][colIdx] > target) {
                colIdx--;
            }
            else {
                rowIdx++;
            }           
        }
        return false;
        
        
    }
};
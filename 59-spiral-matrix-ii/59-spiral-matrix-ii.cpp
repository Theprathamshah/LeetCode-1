class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> matrix(n, vector<int>(n));
        
        
        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = n - 1;
        int cnt = 1;
    
        while(rowStart <= rowEnd and colStart <= colEnd) {
            
            for (int j = colStart; j <= colEnd; j++) {
                matrix[rowStart][j] = cnt++;
            }
            rowStart++;            
            
            for (int i = rowStart; i <= rowEnd; i++) {
                matrix[i][colEnd] = cnt++;
            }
            colEnd--;
            
            for (int j = colEnd; j >= colStart; j--) {
                matrix[rowEnd][j] = cnt++;
            }
            rowEnd--;
            
            for (int i = rowEnd; i >= rowStart; i--) {
                matrix[i][colStart] = cnt++;
            }
            colStart++;
        }
    
        return matrix;
    }
};

/*
COL_MIN(0)
COL_MAX(n-1)

ROW_MIN(0)
ROW_MAX(n-1)


1->2->3 (everytime i hit COL_MAX, will reduce COL_MAX-- means next time we will not traverse to that point

reach(ROW_MAX) means ROW_MAX--
reach(ROW_MIN) Means ROW_MIN++









*/
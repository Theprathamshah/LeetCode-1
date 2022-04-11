class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int nRows = grid.size();
        int nCols = grid[0].size();
        
        k = k % (nRows*nCols);
        
        vector<vector<int>> result(nRows, vector<int>(nCols));
        
        int g_1d, r_1d, r_c, r_r;
        
        for(int g_r = 0; g_r < nRows; g_r++) {
            for(int g_c = 0; g_c < nCols; g_c++) {
                
                g_1d = g_r * nCols +  g_c;
                
                r_1d = (g_1d + k) % (nRows*nCols);
                
                r_r = r_1d/nCols;
                r_c = r_1d%nCols; 
                
                result[r_r][r_c] = grid[g_r][g_c];                
            }
        }
        return result;        
    }
};
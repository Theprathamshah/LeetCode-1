class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int nRows = grid.size();
        int nCols = grid[0].size();
        
        vector<vector<int>> answer(nRows, vector<int>(nCols));       
        int g_1d, a_1d, a_c, a_r;
        
        for(int g_r = 0; g_r < nRows; g_r++) {
            for(int g_c = 0; g_c < nCols; g_c++) {
                
                // Convert (r,c) into its 1D index in the grid vector
                g_1d = g_r * nCols +  g_c;
                
                // Apply offset to obtain the 1D index in the answer vector
                a_1d = (g_1d + k) % (nRows*nCols);
                
                // Convert the 1D index back to the 2D represention in the answer vector
                a_r = a_1d / nCols;
                a_c = a_1d % nCols; 
                
                // (g_r, g_c) + offset --> (a_r, a_c)
                answer[a_r][a_c] = grid[g_r][g_c];                
            }
        }
        return answer;        
    }
};
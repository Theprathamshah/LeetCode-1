class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        _rows = grid.size();
        _cols = grid[0].size();
        
        int area = 0, maxArea = 0;
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                
                //Reset area
                area = 0;
                
                if (grid[i][j] == 1) { // land
                    dfs(grid, i, j, area);
                    maxArea = max(area, maxArea);                        
                }                
            }
        }
        return maxArea;        
    }
private:
    int _rows;
    int _cols;
    
    void dfs(vector<vector<int>>& grid, int row, int col, int &area)
    {        
        vector<int> rowDir = {1, -1, 0, 0};
        vector<int> colDir = {0, 0, 1, -1};
        
        // I am marking it visited
        grid[row][col] = 2;
        
        // Update area
        area++;
        
        int r, c;
        
        for(int i = 0; i < rowDir.size(); i++) {
            r = row + rowDir[i];
            c = col + colDir[i];
            
            if (r >= 0 and r < _rows and c >= 0 and c < _cols and grid[r][c] == 1) {
                    dfs(grid, r, c, area);
            }
        }        
    }        
};

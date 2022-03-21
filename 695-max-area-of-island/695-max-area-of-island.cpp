class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        _rows = grid.size();
        _cols = grid[0].size();
        
        int area = 0, maxArea = 0;
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                
                if (grid[i][j] == 1) { // land
                    area = dfs(grid, i, j);
                    maxArea = max(area, maxArea);                        
                }                
            }
        }
        return maxArea;        
    }
private:
    int _rows;
    int _cols;
    
    int dfs(vector<vector<int>>& grid, int row, int col)
    {        
        vector<int> rowDir = {1, -1, 0, 0};
        vector<int> colDir = {0, 0, 1, -1};
        
        // I am marking it visited
        grid[row][col] = 2;
                
        int smallerArea = 0;        
        
        int r, c;
        
        for(int i = 0; i < rowDir.size(); i++) {
            r = row + rowDir[i];
            c = col + colDir[i];
            
            if (r >= 0 and r < _rows and c >= 0 and c < _cols and grid[r][c] == 1) {
                    smallerArea += dfs(grid, r, c);
            }
        }
        
        // Add 1 for the current cell
        return 1 + smallerArea;
    }        
};

class Solution {
private:
    int ROW_MIN, COL_MIN, ROW_MAX, COL_MAX;
    bool isValidLand(vector<vector<char>>& grid, int i, int j) {        
        return (i >= ROW_MIN and i <= ROW_MAX and j >= COL_MIN and j <= COL_MAX and grid[i][j] == '1') ? true : false;        
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        
        // if(!isValidLand(grid, i,j)) {return;}
            
        // If we get here, means we are at a valid land. now we need to explore all the neighboring cells to see how big is our island.
        
        // first thing we will do is to mark ourselves as visited
        grid[i][j] = '0';
        
        // Now lets explore our neighbors. If we find a land, we will keep marking it as 0 so we don't keep going back and forth!
        array<int,4> di = {-1, 0, 1, 0};
        array<int,4> dj = {0, 1, 0, -1};        
        for(int k = 0; k < di.size(); k++) {
            if(isValidLand(grid,i + di[k], j + dj[k])) {
                dfs(grid, i + di[k], j + dj[k]);    
            }            
        }        
    }
    
    
public:
    int numIslands(vector<vector<char>>& grid) {
                
        ROW_MIN = 0; COL_MIN = 0; ROW_MAX = grid.size() - 1; COL_MAX = grid[0].size() - 1;
        
        int numIslands = 0;
        
        for (int i = ROW_MIN; i <= ROW_MAX; i++) {
            for (int j = COL_MIN; j <= COL_MAX; j++) {
                
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
};
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> temp(m, vector<int>(n));
        
        vector<int> x_dir = {-1,-1, 0, 1 ,1,  1,  0, -1};
        vector<int> y_dir = { 0, 1, 1, 1 ,0, -1, -1, -1};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                int count_0 = 0;
                int count_1 = 0;                
                
                // Count live and dead neighbours
                for(int z = 0; z < x_dir.size(); z++) {
        
                    int x_temp = i + x_dir[z]; 
                    int y_temp = j + y_dir[z]; 
                    
                    if( x_temp >= 0 and x_temp < m and y_temp >= 0 and y_temp < n) {
                        board[x_temp][y_temp] == 0 ? count_0++ : count_1++;                    
                    }                    
                }
                
                // Take a snapshot
                temp[i][j] = board[i][j];
                
                
                if(board[i][j] == 1) { // Any live cell with - 
                    //1. fewer than two live neighbors dies as if caused by under-population.
                    //3. more than three live neighbors dies, as if by over-population.
                    if(count_1 < 2 or count_1 > 3) {
                        temp[i][j] = 0;
                    }                    
                } 
                else { // 4. Any dead cell with -
                    if(count_1 == 3) {
                        temp[i][j] = 1;
                    }
                }
            }
        }
        
        // temp has the snapshop. copy it back to board
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = temp[i][j];
            }
        }
    }
};
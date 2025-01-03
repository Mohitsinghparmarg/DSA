class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); 
                    visited[i][j] = 1;   
                }
            }
        }
        
        int tm = 0;
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        
      
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 1; 
                    grid[nrow][ncol] = 2;   
                }
            }
        }
        
      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) { 
                    return -1;
                }
            }
        }
        return tm;
    }
};

//  Company Tags : OLA, Goldman Sachs, Google (Google asked with small variation)
// Recursion + Memoization

class Solution {
public:

    int t[201][201];

    int solve(vector<vector<int>>& grid,int i,int j, int m,int n){
            
            if(i == m-1 && j == n-1){ // it is my destiny
                   return grid[i][j];
             }
            if(t[i][j] != -1){
                  return t[i][j];
            }
            if(i == m-1){  // I just can move in Right side only...
                  return t[i][j] = grid[i][j] + solve(grid,i,j+1,m,n);
            }
           else if(j == n-1){  // I just can move in Down side only...
                  return t[i][j] = grid[i][j] + solve(grid,i+1,j,m,n);
            }
          else{ // this is in between where I can move in both side Right as well as Down...
                   return t[i][j] = grid[i][j] + min(solve(grid,i,j+1,m,n),solve(grid,i+1,j,m,n));
          }

    }
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        memset(t,-1,sizeof(t));
        return solve(grid,0,0,m,n);
        
    }
};
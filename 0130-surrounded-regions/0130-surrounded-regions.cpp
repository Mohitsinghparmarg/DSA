class Solution {
public:

  void dfs(int row, int col,vector<vector<char>>& board,vector<vector<int>> & visit,int n,int m){
               
               visit[row][col] = 1;

               // now we will have to check for up,down,left,right
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};

             for(int i = 0; i<4; i++){
                    int newrow = row + delRow[i];
                    int newcol = col + delCol[i];
                   if(newrow >= 0 && newrow < n && newcol >= 0 && newcol <m &&
                        board[newrow][newcol] == 'O' && !visit[newrow][newcol]){
                             dfs(newrow,newcol,board,visit,n,m);
                        }
             }

  }



    void solve(vector<vector<char>>& board) {
             
             int n = board.size();
             int m = board[0].size();
             vector<vector<int>>visit(n,vector<int>(m,0));
            
            for(int i = 0; i<m; i++){
                
                // 0th row
                if(board[0][i] == 'O' && !visit[0][i]){
                    dfs(0,i,board,visit,n,m);
                }
                // (n-1)th row
                if(board[n-1][i] == 'O' && !visit[n-1][i]){
                      dfs(n-1,i,board,visit,n,m);
                }
            }
            for(int i = 0; i<n; i++){
                 
                 // 0th column
                 if(board[i][0] == 'O' && !visit[i][0]){
                       dfs(i,0,board,visit,n,m);
                 }
                 // (m-1)th column
                 if(board[i][m-1] == 'O' && !visit[i][m-1]){
                       dfs(i,m-1,board,visit,n,m);
                 }
            }
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(board[i][j] == 'O' && !visit[i][j]){
                        board[i][j] = 'X';
                    }
                }
            }
    }
};
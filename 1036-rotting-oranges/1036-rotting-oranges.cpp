class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        queue<pair<pair<int,int>,int>> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    pq.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        int ans = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!pq.empty())
        {
            int r = pq.front().first.first;
            int c = pq.front().first.second;
            int time = pq.front().second;
            pq.pop();
            ans = max(ans,time);
            for(int i=0;i<4;i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && vis[nrow][ncol]!=2)
                {
                    pq.push({{nrow,ncol},time+1});
                    vis[nrow][ncol] = 2;

                }

            }

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
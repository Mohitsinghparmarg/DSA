class Solution {
public:


    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true; 
        for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor) {
            if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited); 
            }
        }
    }

        int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false); 
        int provinceCount = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, isConnected, visited); 
                provinceCount++;
            }
        }

        return provinceCount; 
    }

};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> RowMatrix(n, 0);
        vector<int> ColMatrix(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    RowMatrix[i] = 1;
                    ColMatrix[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (RowMatrix[i] == 1 || ColMatrix[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
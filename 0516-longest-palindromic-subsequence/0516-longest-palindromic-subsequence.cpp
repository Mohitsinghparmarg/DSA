class Solution {
public:
    int longestPalindromeSubseq(string s) {
          
          string s2 = s;
          reverse(s2.begin(),s2.end());

          int m = s.size();
          int n = s.size();
          int t[m + 1][n + 1];

         for(int i = 0; i<m+1; i++){
            for(int j = 0; j<n+1; j++){
                if(i == 0 || j== 0){
                    t[i][j] = 0;
                }
            }
         }
         for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                if(s[i-1] == s2[j-1]){
                     t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
         }
        return t[m][n];
    }
};
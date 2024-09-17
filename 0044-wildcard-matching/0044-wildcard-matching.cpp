class Solution {
public:
    bool isMatch(string s, string p) {
            
            int n = p.size(); // pattern
            int m = s.size();

            vector<vector<bool>>t(n+1,vector<bool>(m+1,false));
            t[0][0] = true;
            for(int j = 1; j<=m; j++){
                t[0][j] = false;
            }
         for(int i = 0; i<=n; i++){
               bool flag = true;
             for(int ii = 1; ii<=i; ii++){
                  if(p[ii-1]!= '*'){
                       flag = false;
                       break;
                  }
             }
            t[i][0] = flag;
         }
        for(int i = 1; i<=n; i++){
             for(int j = 1; j<=m;j++){
                  if(p[i-1] == s[j-1] || p[i-1] == '?'){
                      t[i][j] = t[i-1][j-1];
                  }
                 else if(p[i-1] == '*'){
                      t[i][j] = t[i-1][j] || t[i][j-1];
                 }
                else{
                      t[i][j] = false;
                }
             }
        }   
       return t[n][m]; 
    }
};
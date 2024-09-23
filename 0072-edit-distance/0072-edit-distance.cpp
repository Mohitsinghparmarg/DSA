class Solution {
public:

    int m,n;
    int t[501][501];

    int solve(string& word1, string& word2,int m,int n){
             
            if( m == 0 || n == 0){
                   return m + n;
            }
            if(t[m][n] != -1){
                 return t[m][n];
            }
            if(word1[m-1] == word2[n-1]){ 
                     return t[m][n] =  solve(word1,word2,m-1,n-1);
            }
           else{
                   int insertChar  = 1 + solve(word1,word2,m,n-1);
                   int deleteChar  = 1 + solve(word1,word2,m-1,n);
                   int replaceChar = 1 + solve(word1,word2,m-1,n-1);
                 return t[m][n] =  min(min(insertChar,deleteChar),replaceChar);
            }
        return -1;
    }

    int minDistance(string word1, string word2) {
          
          m = word1.size();
          n = word2.size();
          memset(t,-1,sizeof(t));
         return solve(word1,word2,m,n);
    }
};
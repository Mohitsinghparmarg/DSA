class Solution {
public:

    int m,n;
    int t[501][501];

    int solve(string& word1, string& word2,int i,int j){
             
            if(i == m){
                 return n-j; // insert kro bhai word1 me yaar...
             }
           else if(j == n){
                  return m-i; // delete kro word1 m se kuch characters bhai...
             }
            if(t[i][j] != -1){
                 return t[i][j];
            }
           else if(word1[i] == word2[j]){ //  hn aage badh jaao bhai...
                     return t[i][j] =  solve(word1,word2,i+1,j+1);
            }
           else{
                   int insertChar  = 1 + solve(word1,word2,i,j+1);
                   int deleteChar  = 1 + solve(word1,word2,i+1,j);
                   int replaceChar = 1 + solve(word1,word2,i+1,j+1);
                 return t[i][j] =  min(min(insertChar,deleteChar),replaceChar);
           }
        return -1;
    }

    int minDistance(string word1, string word2) {
          
          m = word1.size();
          n = word2.size();
          memset(t,-1,sizeof(t));
         return solve(word1,word2,0,0);
    }
};
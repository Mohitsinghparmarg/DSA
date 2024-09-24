class Solution {
public:
      
      int t[101];
   int solve(string& s, int i,int& n){
          
           if(t[i] != -1){
                return t[i];
           }
           if(i == n){
                 return t[i] = 1; 
           }
           if(s[i] == '0'){
                 return t[i] = 0;
           }

           int ans = solve(s,i+1,n);

         if(i+1 < n){
            if( s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                  ans += solve(s,i+2,n);
           }
         }
        return t[i] =  ans;
    }
    int numDecodings(string s) {
          
          int n = s.size();
          memset(t,-1,sizeof(t));
          return solve(s,0,n);
    }
};
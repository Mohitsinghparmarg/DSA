class Solution {
public:
    int climbStairs(int n) {
          
          int t[n+1];
          memset(t,-1,sizeof(t));
          if(n<=2) return n;
          t[0] = 0;
          t[1] = 1;
          t[2] = 2;
        for(int i = 3; i<n+1; i++){
             
             t[i] = t[i-1] + t[i-2];
        }
        return t[n];
          
    }
};
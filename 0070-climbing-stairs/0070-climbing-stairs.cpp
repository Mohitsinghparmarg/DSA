class Solution {
public:
    int climbStairs(int n) {
          
         vector<int>v(n+1);

          if( n == 1 || n == 2 || n == 3){
                 return n;
          }
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
      for(int i = 3; i<= n; i++){
              v[i] = v[i-1] + v[i-2];
      }
    return v[n];
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          
          unordered_map<char,int>mpp;
          int l = 0, r = 0, maxLen = 0;

        while(r < s.size()){

             if(mpp.find(s[r]) != mpp.end()){
                  
                  if(mpp[s[r]] >= l){
                      l = mpp[s[r]] + 1;
                  }
             }
            int len = (r - l + 1);
            maxLen = max(maxLen,len);
            mpp[s[r]] = r;
            r++;
        }
     return maxLen;
    }
};
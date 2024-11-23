class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           
              int maxLen = 0;
              
           for(int i = 0; i < s.size(); i++){
                  
                  unordered_map<char,int>mpp;
                 
                for(int j = i; j < s.size(); j++){
                      
                      if(mpp.find(s[j]) != mpp.end()){
                            break;
                      }
                    int len = (j - i + 1);
                    maxLen = max(maxLen,len);
                    mpp[s[j]] = 1;
                }
           }
        return maxLen;
    }
};
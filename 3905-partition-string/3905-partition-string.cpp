class Solution {
public:
    vector<string> partitionString(string s) {

               set<string>seen;
               vector<string>ans;
               string curr = "";
            for(int i = 0; i < s.size(); i++){
                   curr += s[i];
                 if(seen.find(curr) == seen.end()){
                        ans.push_back(curr);
                        seen.insert(curr);
                        curr = "";
                 }
            }
        return ans;
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {
            
            int n = chars.size();
            int index = 0;
            int i = 0;
         while(i < n){
                
                char current_character = chars[i];
                int count = 0;
              while(i < n && current_character == chars[i]){
                         count++;
                         i++;
              }
            chars[index] = current_character;
             index++;
            if(count > 1){
                 string s = to_string(count);
                for(char ch : s){
                      chars[index] = ch;
                      index++;
                }
            }
         }
        return index;
    }
};
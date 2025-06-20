class Solution {
public:
    int maxDistance(string s, int k) {
            
            int east = 0;
            int west = 0;
            int north = 0;
            int south = 0;
            int Maximum_Steps = 0;
          for(int i = 0; i < s.size(); i++){
                 if(s[i] == 'E'){
                       east++;
                 }
                 if(s[i] == 'W'){
                     west++;
                 }
                 if(s[i] == 'N'){
                    north++;
                 }
                 if(s[i] == 'S'){
                    south++;
                 }
               int Current_Manhattan_Distance = abs(east - west) + abs(north - south);
               int Number_Of_Steps = i + 1;
               int Wasted_Steps = Number_Of_Steps - Current_Manhattan_Distance;
               int Extra_Steps = 0;
             if(Wasted_Steps != 0){
                    Extra_Steps = min(2 * k , Wasted_Steps);
             }
             Maximum_Steps = max(Current_Manhattan_Distance + Extra_Steps , Maximum_Steps);
          }
        return Maximum_Steps;
    }
};
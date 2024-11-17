class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
            
            int five = 0;
            int ten = 0;
            int i = 0;
          while(i < bills.size()){
             
             if(bills[i] == 5)
                   five++;
             else if(bills[i] == 10)
                  {
                       if(five){
                           five--;
                           ten++;
                       }
                       else
                         return false;
                  }
            else{
                  if(ten && five){
                           five--;
                           ten--;
                    }
                   else if(five >= 3){
                         five -= 3;
                    }
                   
                    else
                       return false;
            }    
            i++;
         }
         return true;
    }
};
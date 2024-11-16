/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

   ListNode* interSectionPoint(ListNode* small,ListNode* large,int d){
            
            while(d){
                 d--;
                 large = large->next;
            }
            while(small != large){
                    
                    small = small->next;
                    large = large->next;
            }
         return small;


   }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            
            ListNode* temp1 = headA;
            ListNode* temp2 = headB;
          int temp1_len1 = 0;
          int temp2_len2 = 0;

        while(temp1 != NULL){
              temp1_len1++;
              temp1 = temp1->next;
        }
        while(temp2 != NULL){
              temp2_len2++;
              temp2 = temp2->next;
        }


        if(temp1_len1 < temp2_len2){
               return interSectionPoint(headA,headB,temp2_len2 - temp1_len1);
        }
        else{
               return interSectionPoint(headB,headA,temp1_len1 - temp2_len2);
        }
     return NULL;
    }
};
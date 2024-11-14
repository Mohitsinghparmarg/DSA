/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
           
           ListNode* temp = head;
           int count = 0;
         while(temp != NULL){
               count++;
               temp = temp->next;
         }
        
         if(count == n){
             ListNode* newHead = head->next;
             delete head;
             return newHead;
        }
        count = count - n;
        temp = head;

      while(temp != NULL && temp->next != NULL){
               
               count--;
              if(count == 0){
                   ListNode* deleteNode = temp->next;
                   temp->next = temp->next->next;
                   delete deleteNode;
                   break;
              }
              temp = temp->next;
      }
      return head;
    }
};
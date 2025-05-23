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
     
    ListNode* ReverseAfterMiddleNode(ListNode* head){
               
               if(head == NULL || head->next == NULL){
                      return head;
               }
               ListNode* newHead = ReverseAfterMiddleNode(head->next);
               ListNode* front = head->next;
               front->next = head;
               head->next = NULL;
             return newHead;
    }
     
    bool isPalindrome(ListNode* head) {
           
           ListNode* slow = head;
           ListNode* fast = head;
          while(fast->next != NULL && fast->next->next != NULL){
                 slow = slow->next;
                 fast = fast->next->next;
          }
         ListNode* newHead =  ReverseAfterMiddleNode(slow->next);
         slow = head;
         fast = newHead;
        while(fast != NULL){
               if(slow->val != fast->val){
                      ReverseAfterMiddleNode(newHead);
                      return false;
               }
               slow = slow->next;
               fast = fast->next;
        }
        ReverseAfterMiddleNode(newHead);
        return true;
    }
};
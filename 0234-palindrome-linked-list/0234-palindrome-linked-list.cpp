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
    
    ListNode* reverseAfterMiddle(ListNode* head) {
          
          if(head == NULL || head->next == NULL){
                return head;
          }
        ListNode* newNode = reverseAfterMiddle(head->next);
        ListNode* front = head->next;
        front->next     = head;
        head->next      = NULL;
      return newNode;
    }

    bool isPalindrome(ListNode* head) {
         
         if(head == NULL || head->next == NULL)
                 return true;
           ListNode* slow = head;
           ListNode* fast = head;
         while(fast->next != NULL && fast->next->next != NULL){
                  
                  slow = slow->next;
                  fast = fast->next->next;
          }
        ListNode* newNode = reverseAfterMiddle(slow->next);
        slow = head;
        fast = newNode;
       while(fast != NULL){
              if(slow->val != fast->val){
                   reverseAfterMiddle(newNode);
                   return false;
              }
            slow = slow->next;
            fast = fast->next;
       }
     reverseAfterMiddle(newNode);
      return true;
    }
};
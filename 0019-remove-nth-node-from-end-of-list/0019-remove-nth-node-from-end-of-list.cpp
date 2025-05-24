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
             int length = 0;
            while(temp != NULL){
                  length++;
                  temp = temp->next;
            }
         if(length == n){
              ListNode* newHead = head->next;
              delete head;
              return newHead;
         }
         length -= n;
        temp = head;
        while(temp != NULL && temp->next != NULL){
              length--;
            if(length == 0){
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
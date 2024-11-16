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
    ListNode* deleteMiddle(ListNode* head) {
           
           ListNode* temp = head;
           int len = 0;
         while(temp != NULL){
               len++;
               temp = temp->next;
         }
        if(head == NULL || head->next == NULL){
                return NULL;
                 
        }
        len /= 2;
        temp = head;
        while(temp != NULL){
             
             len--;
             if(len == 0){
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
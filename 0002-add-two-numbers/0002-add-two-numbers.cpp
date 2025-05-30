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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
             
             ListNode* temp1 = l1;
             ListNode* temp2 = l2;
             int sum = 0;
             int carry = 0;
             ListNode* dummyNode = new ListNode(-1);
             ListNode* curr = dummyNode;
            while(temp1 != NULL || temp2 != NULL){
                     
                     sum = carry;
                        if(temp1 != NULL){
                              sum += temp1->val;
                               temp1 = temp1->next;
                        }
                        if(temp2 != NULL){
                             sum += temp2->val;
                             temp2 = temp2->next;
                        }
                      int unit_digit = sum % 10;
                      carry = sum / 10;
                      ListNode* newNode = new ListNode(unit_digit); 
                      curr->next = newNode;
                      curr = newNode;
                    
            }
        if(carry){
              ListNode* newNode = new ListNode(carry);
              curr->next = newNode;
              curr = curr->next;
        }
        return dummyNode->next;
    }
};
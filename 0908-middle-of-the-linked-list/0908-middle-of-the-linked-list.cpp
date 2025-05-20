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
    ListNode* middleNode(ListNode* head) {
              ListNode*temp = head;
              int length = 0;
            while(temp != NULL){
                  length++;
                  temp = temp->next;
            }
            length = length/2 + 1;
            temp = head;
          while(temp != NULL){
                 length--;
                if(length == 0){
                      break;
                }
                temp = temp->next;
          }
        return temp;
    }
};
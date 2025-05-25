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
        
        if(head == NULL || head->next == NULL){
                return NULL;
        }
        ListNode* temp = head;
        int length = 0;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        length /= 2;
        temp = head;
       
        while (temp != NULL && temp->next != NULL) {
            length--;
            if (length == 0) {
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
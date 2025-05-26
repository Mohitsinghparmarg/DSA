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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        unordered_map<ListNode*, int> mpp;

        while (temp1 != NULL || temp2 != NULL) {

            if (mpp.find(temp1) != mpp.end()) {
                return temp1;
            }
            if (temp1 != NULL) {
                mpp[temp1] = 1;
                temp1 = temp1->next;
            }
            if (mpp.find(temp2) != mpp.end()) {
                return temp2;
            }
            if (temp2 != NULL) {
                mpp[temp2] = 1;
                temp2 = temp2->next;
            }
        }
        return NULL;
    }
};
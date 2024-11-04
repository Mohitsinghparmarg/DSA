/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         
        if(!head){
             return NULL;
        }  
        map<Node*,Node*>mpp;
        Node*curr = head;
        Node*prev = NULL;
        Node*newNode = NULL;
     while(curr != NULL){
           
           Node*temp = new Node(curr->val);
           mpp[curr] = temp;
          if(newNode == NULL){
                newNode = temp;
                prev    = temp;
          }
          else{
                prev->next = temp;
                prev = temp;
          }
        curr = curr->next;
     }
     
     curr = head;
     Node* tempNode = newNode;

     while(curr != NULL){
          
          if(curr->random == NULL){
               tempNode->random = NULL;
          }
          else{
               tempNode->random = mpp[curr->random];
          }
          tempNode = tempNode->next;
        curr = curr->next;
     } 
    return newNode;
    }
};
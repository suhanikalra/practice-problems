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
    void deleteNode(ListNode* node) {
        ListNode*prev=NULL;
        ListNode*next=node->next;

        while(node!=NULL and node->next!=NULL){
            node->val=node->next->val;
            prev=node;
            node=node->next;
            
        }
        if( node->next==NULL)prev->next=NULL;


        
    }
};
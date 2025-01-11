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

    ListNode* deleteDuplicates(ListNode* head) {
        if(head== nullptr or head->next==NULL)return head;
       ListNode* first=head;
       ListNode* second=head->next;

       while(second!=NULL){
        if(first->val!= second->val){first=first->next;second= second->next;}
        else{ first->next= second->next; second= second->next;}

       }
       return head;
        
    }
};
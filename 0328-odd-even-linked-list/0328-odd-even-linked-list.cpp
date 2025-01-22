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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL)return head;
        ListNode* odd= head;
        ListNode* even= head->next;

        ListNode* temp= head->next;
        while(even and even->next){
            odd->next=even->next;
            even->next=even->next->next;
            odd= odd->next;
            even= even->next;
            
        }
        odd->next= temp;
       
        return head;

    }
};
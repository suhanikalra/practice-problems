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
ListNode* reverse(ListNode* head){
    if(head== nullptr or head->next==nullptr){return head;}
        ListNode* curr= head;
        ListNode* prev= nullptr;
        ListNode* temp= head;
        while(curr!= NULL){
            temp= curr->next;
            curr->next=prev;
            prev= curr;
            curr= temp;
        }
        return prev;
    
}
    bool isPalindrome(ListNode* head) {
    if(head== nullptr or head->next==nullptr){return true;}

        ListNode* slow= head;
        ListNode* fast= head;
        ListNode* slowprev=NULL;
        while(fast!=NULL and fast->next!= nullptr){
            fast= fast->next->next;
            slowprev=slow;
            slow=slow->next;

        }

    slowprev->next=NULL;
      ListNode* prev=  reverse(slow);
        

        while(head!= NULL && prev!=NULL){
            if(head->val!= prev->val)return false;
            head= head->next;
            prev= prev->next;

        }
        return true;

    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* temp= head;int count=0;
        if(head== nullptr)return head;
        while(temp){
            temp=temp->next;
            count++;
        }
        if(count==n)return head->next;
        if(count<n)return head;
        ListNode* dummy= head;
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            
             if( fast==NULL)return head;
             fast= fast->next;
        }
        while(fast!= nullptr){
            fast= fast->next;
              dummy= slow;
            slow= slow->next;
          
        }
      dummy->next= slow->next;
      delete slow;
      
        return head;

    }
};
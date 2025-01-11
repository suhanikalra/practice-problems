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
    ListNode* rotateRight(ListNode* head, int n) {
         ListNode* temp= head;int count=0;
        if(head== nullptr)return head;
        while(temp){
            temp=temp->next;
            count++;
        }
        if(n % count == 0)return head;
        if(count==n)return head->next;
        if(count<n)n=n%count;
        
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
          
        }dummy->next= nullptr;
         
        ListNode* a= reverse(head);
        head->next=reverse(slow);
        
        return reverse(a);
        
        
    }
};
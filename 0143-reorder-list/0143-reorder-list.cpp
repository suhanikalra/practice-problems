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
    void reorderList(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast= head;

        while( fast and fast->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        
        ///reverse the second half
        ListNode* secondHead= slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;
        while( secondHead){
            ListNode* temp=secondHead->next;
            secondHead->next= prev;
            prev=secondHead;
            secondHead=temp;
        }
        //prev= head now
        secondHead = prev; 
         ListNode* first = head;
        ListNode* second = secondHead;
//merge
        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }

        


    }
};
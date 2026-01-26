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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* A=headA;
       ListNode* B= headB;
       int lengthA=0,lengthB=0;

       while(A){
        A=A->next;
        lengthA++;
       }
       while(B){
        B=B->next;
        lengthB++;
       }

       if(lengthA>lengthB){
        int k=lengthA-lengthB;
        while(k--){
            headA=headA->next;
        }
       }
       else {
        int k=lengthB-lengthA;
        while(k--){
            headB=headB->next;
        }

       }

       while(headA and headA!=headB  ){
        headA=headA->next;
        headB=headB->next;
       }
       return headA;
    }
};
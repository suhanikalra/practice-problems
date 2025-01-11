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
        if(headA==NULL or headB==NULL)return NULL;
        int count1=0;int count2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=NULL or temp2!=NULL){
            if(temp1){
                count1++;
                temp1=temp1->next;
            }
            if(temp2){
                count2++;
                temp2=temp2->next;
            }


        }
        cout<<count1<<" "<<count2;
        if(count1>count2){
            int t= count1-count2;
            while(t--){
                headA=headA->next;
            }
        }
        else if(count1<count2) {
            int l= count2-count1;
            while(l--){
                headB=headB->next;
            }
        }
        while(headA != NULL and headB!=NULL){
        if(headA!=NULL and headA==headB)return headB;
        headA= headA->next;headB=headB->next;}

        return nullptr;

        
    }
};
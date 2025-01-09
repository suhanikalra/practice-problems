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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) return head;

        ListNode* count= head;int nodes=0;
       while(count != nullptr) { 
            count = count->next;
            nodes++;
        }
        if(nodes<k)return head;
        //rev first k nodes

        ListNode* curr= head;
        ListNode* prev= nullptr;
        ListNode* temp= nullptr;
        for(int i=0;i<k;i++){
            temp= curr->next;
            curr->next=prev;
            prev= curr;
            curr= temp;

        }
        head->next= reverseKGroup(curr,k);


        return prev;
        
    }
};
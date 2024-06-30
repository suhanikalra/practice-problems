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
    ListNode* swapPairs(ListNode* head) {
      if(head == NULL || head->next == NULL) return head;

        ListNode * temp = head->next->next;
        ListNode * newHead = head->next;

        head->next->next = head;
        head->next =  swapPairs(temp);

        return newHead;
    }
};
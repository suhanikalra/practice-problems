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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ListNode* temp = head;

  
        while (k > 1 && ptr1 != nullptr) {
            ptr1 = ptr1->next;
            k--;
        }

        if (ptr1 == nullptr) {
            return head;
        }

       
        temp = ptr1;

        
        while (ptr1->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

       
        int tempVal = temp->val;
        temp->val = ptr2->val;
        ptr2->val = tempVal;

        return head;
    }
};

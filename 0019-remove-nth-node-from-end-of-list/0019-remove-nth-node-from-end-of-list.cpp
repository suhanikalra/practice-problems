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
        ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
        dummy->next = head; // Point dummy's next to head of the list
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n nodes ahead
        for (int i = 0; i <= n; ++i) {
            if (fast == nullptr) return nullptr; // Handle edge case if n > list size
            fast = fast->next;
        }

        // Move both fast and slow pointers until fast reaches end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        ListNode* toRemove = slow->next;
        slow->next = slow->next->next;
        delete toRemove;

        return dummy->next; // Return the updated head
    }
};

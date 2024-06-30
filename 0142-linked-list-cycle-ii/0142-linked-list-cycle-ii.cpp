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

ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected, find the start of the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Return the node where the cycle starts
        }
    }

    return nullptr; // No cycle found
}
};
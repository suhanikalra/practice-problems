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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* lesshead = new ListNode(0); // Dummy node for less list
        ListNode* morehead = new ListNode(0); // Dummy node for more list
        ListNode* less = lesshead; // Pointer to construct the less list
        ListNode* more = morehead; // Pointer to construct the more list
        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->val < x) {
                less->next = temp;
                less = less->next;
            } else {
                more->next = temp;
                more = more->next;
            }
            temp = temp->next;
        }

        more->next = NULL; // Ensure the end of the more list is NULL//i think yhi line ws mising
        less->next = morehead->next; // Connect the less list with the more list

        return lesshead->next; // Return the head of the new list
    }
};
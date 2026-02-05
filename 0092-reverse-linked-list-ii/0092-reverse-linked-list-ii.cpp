class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* lprev = dummy;

        for (int i = 1; i < left; i++) {
            lprev = lprev->next;
        }

        ListNode* curr = lprev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = lprev->next;
            lprev->next = temp;
        }

        return dummy->next;
    }
};

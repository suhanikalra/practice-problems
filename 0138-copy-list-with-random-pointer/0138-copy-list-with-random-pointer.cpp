/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nextNode;
            curr = nextNode;
        }

        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        curr = head;
        Node* copyHead = head->next;

        while (curr) {
            Node* copyNode = curr->next;
            curr->next = copyNode->next;

            if (copyNode->next)
                copyNode->next = copyNode->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};
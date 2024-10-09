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
        for(auto node=head; node !=nullptr;node= node->next->next ){
            
            auto temp = node->next;
            auto p = new Node(node->val);
            node->next= p;
            p->next= temp;

        }

        for(auto node=head; node !=nullptr;node= node->next->next ){
            auto temp= node->random;
            if(temp != nullptr){node->next->random= temp->next;}
            else node->next->random=nullptr;
        }
auto dummy = new Node(0);
        auto newHead = dummy;
        for (auto node = head; node != nullptr; node = node->next) {
            auto clonedNode = node->next;
            node->next = clonedNode->next;
            newHead->next = clonedNode;
            newHead = clonedNode;
        }

        return dummy->next;
    }
};
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
        if( head==NULL)return NULL;

        for( auto node=head;node!=NULL;node=node->next->next){
            Node* copiedNode= new Node(node->val);
            Node* temp= node->next;
            node->next= copiedNode;
            copiedNode->next= temp;
        }

        for( auto node=head;node!=NULL;node=node->next->next){
            if(node->next and node->random)node->next->random= node->random->next;
            else node->next->random==NULL;
        }
         Node* temp = head;
        Node* newHead = head->next;

        while (temp) {
            Node* copy = temp->next;
            temp->next = copy->next;
            if (copy->next)
                copy->next = copy->next->next;
            temp = temp->next;
        }

        return newHead;




    }
};
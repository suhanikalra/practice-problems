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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         auto cmp = [](ListNode* l, ListNode* r) { return l->val > r->val; };
        priority_queue<ListNode*, vector<ListNode*>,decltype(cmp)> pq(cmp);
        for( auto l: lists){ if( l)pq.push(l);
        }
        ListNode* dummy= new ListNode(0);
        ListNode* head= dummy;

        while( !pq.empty()){
            ListNode* temp= pq.top();
            dummy->next= pq.top();
            pq.pop();
            if(temp->next)pq.push(temp->next);
            dummy=dummy->next;
            

        }
        return head->next;


          
    }
};
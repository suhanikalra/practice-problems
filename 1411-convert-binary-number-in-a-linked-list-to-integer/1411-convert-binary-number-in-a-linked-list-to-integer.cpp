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
    int getDecimalValue(ListNode* head) {
        stack<int>st;
        while(head){
            st.push(head->val);
            head=head->next;

        }
        int ans=st.top();st.pop();int count=0;
        while(!st.empty()){count++;
            ans += st.top()*pow(2,count);st.pop();
        }

        return ans;
    }
};
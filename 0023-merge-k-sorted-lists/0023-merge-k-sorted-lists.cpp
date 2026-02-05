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
ListNode* solve(ListNode* l1,ListNode* l2){
if( l1==NULL )return l2;
if( l2==NULL)return l1;

ListNode* dummy= new ListNode(0);
ListNode* head= dummy;
while( l1!=NULL and l2!=NULL){
    if(l1->val>l2->val){
        dummy->next=l2;
        l2=l2->next;
    }
    else if(l2->val>=l1->val){
        dummy->next=l1;
        l1=l1->next;
    }
    dummy= dummy->next;
}
if(l1!=nullptr)
        {
            dummy->next = l1;
        }
        if(l2!=nullptr)
        {
            dummy->next = l2;
        }

        return head->next;

}
        ListNode*  merge(int start,int end,vector<ListNode*>& lists){
        if( start == end)return lists[start];
        int mid= (end-start)/2+start;
        auto a = merge(start,mid,lists);
        auto b = merge(mid+1,end,lists);
        return solve(a,b);
        

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        int n = lists.size()-1;
        return merge(0,n,lists);
        
    }
};
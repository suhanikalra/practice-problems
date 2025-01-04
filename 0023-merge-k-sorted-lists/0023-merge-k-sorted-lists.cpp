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
ListNode* merge( ListNode*list1,ListNode*list2){
    if(list1==NULL and list2==NULL)return NULL;
    if(list1==NULL)return list2;
    if(list2==NULL)return list1;

    if(list1->val<=list2->val){list1->next=(merge(list1->next,list2));return list1;}
   else{list2->next=(merge(list2->next,list1));return list2;}



}
 ListNode* mergeK(vector<ListNode*>& lists,ListNode*mergeList,int i){
    if(i== lists.size()){
        return mergeList;
    }
        mergeList = merge(lists[i], mergeList);
        return mergeK(lists, mergeList, i + 1);
   
    

 }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if (lists.empty()) return nullptr;

        ListNode* mergeList = nullptr; 
        return mergeK(lists, mergeList, 0);
    }
};
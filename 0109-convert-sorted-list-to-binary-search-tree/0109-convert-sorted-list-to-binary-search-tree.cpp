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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int> &arr,int start,int end){
        if(start>end)return NULL;
        int mid= (end-start)/2+start;
        TreeNode* node= new TreeNode(arr[mid]);
        node->left=solve(arr,start,mid-1);
        node->right =solve(arr,mid+1,end);

        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL )return NULL;
vector<int> arr;
        while(head!= NULL){
            arr.push_back(head->val);
            head= head->next;
        }

       return solve(arr,0,arr.size()-1);
        
    }
};
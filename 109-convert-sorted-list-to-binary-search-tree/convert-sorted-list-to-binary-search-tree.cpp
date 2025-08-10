class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* slow_prev=NULL;
        //get to mid of LL to make it root of bst
        while(fast!=NULL && fast->next!=NULL){
            slow_prev=slow;
            slow=slow->next;
            fast=(fast->next)->next;
        }
        //mid
        TreeNode* root=new TreeNode(slow->val);
        slow_prev->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        return root;
    }
};
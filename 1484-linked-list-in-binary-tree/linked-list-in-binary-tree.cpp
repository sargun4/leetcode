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
 * Definition for a binary tree root->
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     // vector<int> storepaths(TreeNode* root):
//     //     vector<int> ans;
//     //     path += to_string(root->data)
//     //     if(!root->left && !root->right):
//     //         ans.push_back(path);
//     //         return;
//     //     if root->left:
//     //         solve(root->left, path + " ");
//     //     if root->right:
//     //         solve(root->right, path + " ");
//     // storepaths(root, "")
    

//     bool isSubPath(ListNode* head, TreeNode* root) {
//         //store all paths frm root to leaf, then check if LL comes in it
//     }
// };

class Solution {
public:
    vector<TreeNode*> arr;
    bool isSubPath(ListNode* head, TreeNode* root){
        store(head,root);
        for(TreeNode* elmnt:arr){
            if(CheckSubPath(head,elmnt)) return true;
        }
        return false;
    }
    void store(ListNode* head, TreeNode* root){//rec
        if(head==NULL || root==NULL) return;
        if(head->val==root->val){
            arr.push_back(root);
        }
        store(head,root->left);
        store(head,root->right);

    }
    bool CheckSubPath(ListNode* head, TreeNode* root) {
        if(head==NULL) return true;
        if(root==NULL) return false;
        if(head->val==root->val) 
            return (CheckSubPath(head->next,root->left)||CheckSubPath(head->next,root->right));
        return false;
    }
};
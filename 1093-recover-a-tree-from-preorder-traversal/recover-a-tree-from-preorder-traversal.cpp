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
    TreeNode* recoverFromPreorder(string traversal) {
        int idx=0;
        return rec(traversal,idx,0);
    }
    TreeNode* rec(string traversal,int&idx,int depth){
        int n=traversal.size();
        if(idx>=n) return NULL;
        //no of dashes
        int dashctr=0;
        while(idx+dashctr<n && traversal[idx+dashctr]=='-'){
            dashctr++;
        }
        //if no of dashes dosnt match curr depth,return null
        if(dashctr!=depth) return NULL;
        //move idx past dashes
        idx+=dashctr;
        //get node val
        int val=0;
        while(idx<n && isdigit(traversal[idx])){
            val=val*10+(traversal[idx]-'0');
            idx++;
        }
        //create curr node
        TreeNode* node=new TreeNode(val);
        node->left=rec(traversal,idx,depth+1);
        node->right=rec(traversal,idx,depth+1);
        return node;
    }
};
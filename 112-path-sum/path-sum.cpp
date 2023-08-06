#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool inorder(TreeNode* root,int sum,int targetSum){
        if(root==NULL){
            return false;
        }
        sum+=root->val;
        //if we reach leaf node
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum) return true;
            return false;
        }
        bool leftside=inorder(root->left,sum,targetSum);
        bool rightside=inorder(root->right,sum,targetSum);

        return leftside||rightside;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool res=inorder(root,sum,targetSum);
        return res;
    }
};
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         // return false if the root is nullptr
//         if(!root) return false;
//         // if it reaches to the end and the val is equal to the sum, return true
//         if(!root->left && !root->right && root->val == targetSum) return true;
//         // otherwise, we traverse left node and right node with targetSum `sum - root->val`
//         return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum-root->val);
//     }
// };


// int helper(node*root,int targetSum,long int currSum,unordered_map<long int,int> pathcount){
//     if(root==NULL) return 0;
//     currSum+=root->data;
//     int count=pathcount[currSum-targetSum];
//     pathcount[currSum]++;
//     count+=helper(root->left,targetSum,currSum,pathcount)+helper(root->right,targetSum,currSum,pathcount);
//     pathcount[currSum]--; //backtracking
//     return count;
// }
// int pathSum(node *root,int targetSum){
//     unordered_map<long int,int> pathcount;
//     pathcount[0]=1;
//     return helper(root,targetSum,0,pathcount);
// }
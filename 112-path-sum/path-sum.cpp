//bfs
class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        //if root is NULL you can't get any value even zero
        if(root==NULL)
            return false;
        //for BFS to store nodes and keep track of target
        queue<pair<TreeNode*,int>>q; //{node,sum}
        
        //pushed given root and target we need
        q.push({root,target});
        
        //BFS
        while(!q.empty()){

            TreeNode *root=q.front().first;
            target=q.front().second;
            q.pop();
            
            //if there is no left and right child node must be a leaf node
            //and we'll subtract val of that node and check it is zero or not 
            // since root-to-leaf paths are needed.
            if(root->right==NULL && root->left==NULL){//leaf
                if(target-(root->val)==0)
                    return true;//got a path
            }
            //if child present push to queue else ignore
            if(root->left) q.push({root->left,target-(root->val)});
            if(root->right) q.push({root->right,target-(root->val)});
        }
        return false;
    }
};

// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     bool inorder(TreeNode* root,int sum,int targetSum){
//         if(root==NULL){
//             return false;
//         }
//         sum+=root->val;
//         //if we reach leaf node
//         if(root->left==NULL && root->right==NULL){
//             if(sum==targetSum) return true;
//             return false;
//         }
//         bool leftside=inorder(root->left,sum,targetSum);
//         bool rightside=inorder(root->right,sum,targetSum);

//         return leftside||rightside;
//     }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         int sum=0;
//         bool res=inorder(root,sum,targetSum);
//         return res;
//     }
// };
// // class Solution {
// // public:
// //     bool hasPathSum(TreeNode* root, int targetSum) {
// //         // return false if the root is nullptr
// //         if(!root) return false;
// //         // if it reaches to the end and the val is equal to the sum, return true
// //         if(!root->left && !root->right && root->val == targetSum) return true;
// //         // otherwise, we traverse left node and right node with targetSum `sum - root->val`
// //         return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum-root->val);
// //     }
// // };


#include <bits/stdc++.h>
using namespace std;
//BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left==NULL && temp->right==NULL){
                    return depth;
                }
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            depth++;
        }
        return -1;
    }
};
// diff =[sum of node.data from root to target]-[sum of node.data from target to leaf ]

//the 1st part(root to target sum) is constant for a given target in the BST
//2nd part is variable (target to leaf sum) since there can be multiple leaves possible from target.
//to maximise diff, we hv to minimize the 2nd part
// dfs for
// 1. calc the root to target sum
// 2. Minimize and Calculate the target to leaf sum
class Solution {
public:
    int rootToTargetSum(Node*root,int target,Node*&targetNode){
        if(!root) return 0;
        if(root->data==target){
            targetNode=root;
            return root->data;
        }
        if(target>root->data){//move to right
            int sum = rootToTargetSum(root->right, target, targetNode);
            if (sum) return root->data + sum;
        }else{//move left
            int sum = rootToTargetSum(root->left, target, targetNode);
            if (sum) return root->data + sum;
        }
        return 0;
    }
    // From target node, find path to leaf with min sum
    int targetToLeafSum(Node*root){
        if(!root) return INT_MAX;
        if(!root->left && !root->right){//leaf node
            return root->data;
        }
        int l=targetToLeafSum(root->left);
        int r=targetToLeafSum(root->right);
        return root->data + min(l,r);//minimizing 2nd part sum to get max diff
    }
    int maxDifferenceBST(Node *root, int target) {
        Node* targetNode = NULL;
        int pathSum = rootToTargetSum(root, target, targetNode);
        if (!targetNode) return -1;  //target not found
        // Exclude target's data once
        int minLeafSum = targetToLeafSum(targetNode);
        return pathSum-minLeafSum;
    }
};
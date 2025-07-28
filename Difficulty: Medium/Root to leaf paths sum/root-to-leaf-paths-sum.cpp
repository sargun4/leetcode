class Solution {
public:
    int dfs(Node*root,int sum){
        if(!root) return 0;
        sum=sum*10+root->data;
        if(!root->left && !root->right){//leaf ndoe reached
            return sum;
        }
        int lsum=dfs(root->left,sum);
        int rsum=dfs(root->right,sum);
        return lsum+rsum;
    }
    int treePathsSum(Node*root) {
        int sum=0;
        return dfs(root,sum);
    }
};
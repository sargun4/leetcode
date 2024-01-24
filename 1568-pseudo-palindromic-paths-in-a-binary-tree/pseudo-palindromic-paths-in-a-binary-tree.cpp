 
class Solution {
public:
    int res=0;
    void solve(TreeNode* root,vector<int> &ctr){
        if(!root) return;
        ctr[root->val]++;
        if(root->left==NULL && root->right==NULL){ //leaf- got a path
            int oddfreq=0;
            for(int i=1;i<=9;i++){
                if(ctr[i]%2!=0){ //odd freq
                    oddfreq++;
                }
            }
            if(oddfreq<=1){
                res+=1;
            }
        }
        solve(root->left,ctr);
        solve(root->right,ctr);
        ctr[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> ctr(10,0);
        solve(root,ctr);
        return res;
    }
};
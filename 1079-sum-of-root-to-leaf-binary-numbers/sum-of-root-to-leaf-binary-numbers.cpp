class Solution {
public:
    int binToDec(string &s){
        int k=0; int deci=0;
        int n=s.size();
        for(int idx=n-1;idx>=0;idx--){
            deci+=pow(2,k++)*(s[idx]-'0');
        }
        return deci;
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        queue<pair<TreeNode*,string>>q;
        q.push({root,""});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto [node,path]=q.front(); q.pop();
                path+=(node->val + '0');//addin curr node val to path
                if(!node->left && !node->right){//leaf node
                    sum+=binToDec(path);
                }
                if(node->left) q.push({node->left,path});
                if(node->right) q.push({node->right,path});
            }
        }
        return sum;
    }
};
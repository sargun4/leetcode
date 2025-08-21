class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        if(root==NULL) return avg;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();//no of nodes in that lvl
            double sum=0;
            int ctr=n;
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum+=node->val;
            }
            avg.push_back(sum/ctr);//pushing avg
        }
        return avg;
    }
};
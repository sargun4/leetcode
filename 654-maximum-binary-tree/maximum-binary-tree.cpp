class Solution {
public:
    int findMax(vector<int>nums,int s,int e){
        int maxi=s;
        for(int i=s;i<=e;i++){
            if(nums[i]>nums[maxi])
            maxi=i;
        }
        return maxi;
    }
    TreeNode* makeTree(vector<int>nums,int start,int end){
        if(start>end)return NULL;
        int idx=findMax(nums,start,end);
        TreeNode* root=new TreeNode(nums[idx]);
        root->left=makeTree(nums,start,idx-1);
        root->right=makeTree(nums,idx+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return makeTree(nums,0,n-1);
    }
};
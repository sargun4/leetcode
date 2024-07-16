class Solution {
public:
    TreeNode*lca(TreeNode* root,int src,int dest){
        if(!root) return NULL;
        if(root->val==src||root->val==dest){
            return root;
        }
        TreeNode* l=lca(root->left,src,dest);
        TreeNode* r=lca(root->right,src,dest);
        if(l && r) return root;
        return l?l:r;
    }
    bool findpath(TreeNode* lca,int target,string &path){
        if(lca==NULL) return false;
        if(lca->val==target) return true;
        //explore left
        path.push_back('L');
        if(findpath(lca->left,target,path)==true){
            return true;
        }
        path.pop_back();

        //explore right
        path.push_back('R');
        if(findpath(lca->right,target,path)==true){
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcanode=lca(root,startValue,destValue);
        string lcatosrc="";
        string lcatodest="";
        findpath(lcanode,startValue,lcatosrc);
        findpath(lcanode,destValue,lcatodest);
        string res="";
        for(int i=0;i<lcatosrc.length();i++){
            res.push_back('U');
        }
        res+=lcatodest;
        return res;
    }
};
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int> childset; //these cant be root,since they r child of some node
        for(auto &vec:descriptions){
            int parent=vec[0];
            int child=vec[1];
            int isleft=vec[2];
            if(mp.find(parent)==mp.end()){ //if that node doesnt exist,make node and store in mp
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if(isleft==1){
                mp[parent]->left=mp[child];
            }else if(isleft==0){ //rchild
                mp[parent]->right=mp[child];
            }
            childset.insert(child);
        }
        //find root;
        for(auto vec:descriptions){
            int parent=vec[0];
            if(childset.find(parent)==childset.end()){//not found
                return mp[parent];
            }
        }
        return NULL;
    }
};
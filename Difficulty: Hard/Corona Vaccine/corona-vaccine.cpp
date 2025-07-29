//saem as https://leetcode.com/problems/binary-tree-cameras/
//a camera node can monitor 4nodes-itself,its parent & its left n right children
class Solution {
public:
    unordered_map<Node*,vector<Node*>> adj;//graph adj list
    unordered_map<Node*,bool> vis;
    void buildGraph(Node* root,Node* parent){
        if(!root) return;
        if(parent){
            adj[root].push_back(parent);
            adj[parent].push_back(root);
        }
        //rec build
        buildGraph(root->left,root);
        buildGraph(root->right,root);
    }
    //dfs-return state if node
    //0-not covered,1=has kit,2=covered(by child);
    int dfs(Node*node,Node*parent,int&kitCtr){
        vis[node]=true;
        bool hasChildNotBeenCovered=false;//atleast 1 childof this node is not covered
        bool hasChildWithCamera=false;//atleast 1 child of this node has kit
        
        for(Node* neigh:adj[node]){
            if(neigh==parent || vis[neigh]){//if neigh is parent or alr vis neigh
                continue;//skip it
            }
            int childState=dfs(neigh,node,kitCtr);
            //if child isnt covered,we may need to place kit at this child
            if(childState==0) hasChildNotBeenCovered=true;
            //if child has kit, this node is covered
            if(childState==1) hasChildWithCamera=true;
        }
        //if any child isnt covered,place kit here
        if(hasChildNotBeenCovered){
            kitCtr++;
            return 1;//place kit on this child
        }
        //if any child has kit,this node is alr covered
        if(hasChildWithCamera){
            return 2;//covered node
        }
        //else no child has kit,all r covered
        return 0;//this node isnt covered
    }
    int supplyVaccine(Node* root) {
        if(!root) return 0;
        buildGraph(root,NULL);
        int kitCtr=0;
        //if root is still not coevred by vaccine after dfs, place kit at root
        int rootState=dfs(root,NULL,kitCtr);
        if(rootState==0){
            kitCtr++;//root needs kit
        }
        return kitCtr;
    }
};
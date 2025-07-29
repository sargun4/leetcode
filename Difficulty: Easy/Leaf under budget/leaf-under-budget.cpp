//do bfs and store leaf n its lvl in map
class Solution {
  public:
    int getCount(Node*root, int k) {
        queue<pair<Node*,int>> q;//{leaf:lvl}
        int lvl=1;
        q.push({root,lvl});
        int ctr=0;
        while(!q.empty()){
            auto curr=q.front();
            Node* node=curr.first;
            int lvl=curr.second;
            q.pop();
            if(!node->left && !node->right){
                if(lvl>k){
                    return ctr;
                }else{
                    ctr++;
                    k=k-lvl;
                }
            }else{
                if(node->left){
                    q.push({node->left,lvl+1});
                }
                if(node->right){
                    q.push({node->right,lvl+1});
                }
            }
        }
        return ctr;
    }
};
class Solution {
  public:
    vector<vector<int>> binTreeSortedLevels(int arr[], int n) { 
        queue<pair<int,int>> q;//{node,lvl}
        int root=arr[0];
        q.push({root,0});
        vector<vector<int>> ans;
        while(!q.empty()){
            int sz=q.size();
            vector<int> temp;
            for(int i=0;i<sz;i++){
                auto it=q.front(); q.pop();
                int node=it.first;
                int lvl=it.second;
                temp.push_back(node);
                if(2*lvl+1<n){//lchild
                    q.push({arr[2*lvl+1],2*lvl+1});
                }
                if(2*lvl+2<n){//rchild
                    q.push({arr[2*lvl+2],2*lvl+2});
                }
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> degree;//{node:degree}
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            degree[u]++;
            degree[v]++;
        }
        for(auto &it:degree){
            if(it.second==edges.size())//node w (degree of node=no of edges) is the centre
                return it.first; 
        }

        return -1;
    }
};
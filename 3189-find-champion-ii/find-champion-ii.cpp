class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        //findnode with indegree[node]=0
        vector<int> indeg(n,0);
        for(auto e:edges){
            int u=e[0]; int v=e[1];
            indeg[v]++;
        }
        int champ=-1;
        int ctr=0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                champ=i;
                ctr++;
            }
        }
        if(ctr>1){
            return -1;
        }
        return champ;
    }
};
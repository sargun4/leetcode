using p=pair<int,pair<int,int>>;
class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries){
        int m=grid.size();
        int n=grid[0].size();
        int q=queries.size();
        vector<int> ans(q,0);
        vector<pair<int,int>> sortedQueries;//{queries[i],original_idx}
        for(int i=0;i<q;i++){
            sortedQueries.push_back({queries[i],i});
        }
        sort(begin(sortedQueries),end(sortedQueries));
        priority_queue<p,vector<p>,greater<>> pq;//minheap-{val,{x,y}}
        pq.push({grid[0][0],{0,0}});
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[0][0]=true;
        int pts=0; //ctr of reachable cells with grid value < current query

        for(int i=0;i<q;i++){
            int queryVal=sortedQueries[i].first;
            int idx=sortedQueries[i].second;
            // explore all reachable cells with grid value < queryVal
            while(!pq.empty() && pq.top().first < queryVal){
                auto curr=pq.top(); pq.pop();
                int x=curr.second.first;
                int y=curr.second.second;
                pts++;//1 more grid w val< found
                for(auto &d:dirns){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(isValid(nx,ny,m,n) && !vis[nx][ny]){
                        pq.push({grid[nx][ny],{nx,ny}});
                        vis[nx][ny]=true;
                    }
                }
            }
            ans[idx]=pts;
        }
        return ans;
    }
};
//time%2!=0 : R or D movt
class Solution {
public:
    typedef long long ll;
    typedef pair<long long,pair<int,pair<int,int>>> p;
    // bool isValid(int i,int j,int m,int n){
    //     return i>=0 && j>=0 && i<m && j<n;
    // }
    // vector<vector<int>>dirns={{1,0},{0,1}};//only R and D
    long long minCost(int m, int n, vector<vector<int>>& waitCost){
        vector<vector<ll>> dist(m,vector<ll>(n,1e18));
        //dist mat: dist[x][y] = min cost to reach (x, y)
        dist[0][0]=1;
        int startcost=1;//(0+1)*(0+1)
        priority_queue<p,vector<p>,greater<p>> pq;
        //start from (0,0) at time = 1 with cost = 1
        pq.push({startcost,{1,{0,0}}});//{cost,{time,{x,y}}};
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            ll cost=it.first;
            int time=it.second.first;
            int x=it.second.second.first;
            int y=it.second.second.second;

            if(x==m-1 && y==n-1){//reached bottom right cell
                return cost;
            }
            // Even time, we must wait in the current cell
            if(time%2==0){//even time-get wait cost and add to curr cost
                ll newcost=cost+waitCost[x][y];
                pq.push({newcost,{time+1,{x,y}}});
            }else{//odd time-R or D movt 
                int nx=x+1; 
                int ny=y+1;
                if(nx<m){//D
                    ll entrycost=1LL*(nx+1)*(ny);
                    ll newcost=cost+entrycost;
                    if(newcost<dist[nx][y]){
                        dist[nx][y]=newcost;
                        pq.push({newcost,{time+1,{nx,y}}});
                    }
                }
                if(ny<n){//R
                    ll entrycost=1LL*(nx)*(ny+1);
                    ll newcost=cost+entrycost;
                    if(newcost<dist[x][ny]){
                        dist[x][ny]=newcost;
                        pq.push({newcost,{time+1,{x,ny}}});
                    }
                }
            }
        }
        return -1;
    }
};
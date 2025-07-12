
//rottin oranges-same
class Solution {
public:
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int helpaterp(vector<vector<int>> hospital) {
        int m=hospital.size();
        int n=hospital[0].size();
        int totalPatients=0;
        queue<pair<int,int>> q;//infected q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(hospital[i][j]!=0) totalPatients++;//total count
                if(hospital[i][j]==2){//infected patient
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        int infected = q.size();
        while(!q.empty()){
            int sz = q.size();
            bool spread = false;
            for (int i = 0; i < sz; i++) {
                auto curr=q.front(); q.pop();
                int x=curr.first;
                int y=curr.second;
                for(auto d:dirns){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    //in bounds and not yet infected cell
                    if(isValid(nx,ny,m,n) && hospital[nx][ny]==1){
                        hospital[nx][ny]=2;//infect it
                        q.push({nx,ny});
                        spread = true;
                        infected++;
                    }
                }
            }
            if (spread) time++; //Only increase time if new infections occurred
        }
        return (totalPatients==infected) ? time:-1 ;
    }
};

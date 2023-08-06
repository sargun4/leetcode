#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minThrow(int n, int arr[]){
        int moves[35];//to store end pts of snakes & ladders(S&L) w idx as start and value as end
        bool vis[35];
        //bfs
        memset(moves,-1,sizeof(moves)); //filling -1 in moves
        memset(vis,false,sizeof(vis));//filling false for all nodes in vis
        for(int i=0;i<2*n;i+=2){
            moves[arr[i]]=arr[i+1];//storing end pt of S&L as values
        }
        queue<pair<int,int>> q;
        pair<int,int> p;
        //p.first=cell no
        //p.second=no of turns to reach
        q.push({1,0});
        //first cell

        vis[1]=true;
        while(!q.empty()){
            p=q.front();
            int cell=p.first;
            int turn=p.second;
            if(cell==30) break; //last cell reaches
            q.pop();
            for(int i=cell+1;i<=cell+6 && i<=30;i++){
                pair<int,int> pp;
                if(!vis[i]){
                    pp.second=turn+1;
                    vis[i]=true;
                    if(moves[i]!=-1){
                        pp.first=moves[i];
                    }else{
                        pp.first=i;
                    }
                    q.push(pp);
                }
            }
        }
        return p.second;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}

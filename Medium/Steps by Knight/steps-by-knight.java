//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int N = Integer.parseInt(br.readLine().trim());
            String[] S1 = br.readLine().trim().split(" ");
            String[] S2 = br.readLine().trim().split(" ");
            int[] KnightPos = new int[2];
            int[] TargetPos = new int[2];
            for(int i = 0; i < 2; i++){
                KnightPos[i] = Integer.parseInt(S1[i]);
                TargetPos[i] = Integer.parseInt(S2[i]);
            }
            Solution obj = new Solution();
            int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
            System.out.println(ans);
       }
    }
}

// } Driver Code Ends
class Solution{
    //Function to find out minimum steps Knight needs to reach target position.
    public int minStepToReachTarget(int KnightPos[], int TargetPos[], int n){
        int x1= KnightPos[0];
        int y1= KnightPos[1];
        int x2= TargetPos[0];
        int y2= TargetPos[1];
        int[] dx={-1,1,2,2,1,-1,-2,-2};
        int[] dy={2,2,1,-1,-2,-2,-1,1};
        boolean[][]vis=new boolean[n+1][n+1];
        Queue<Coordinate> q=new LinkedList<Coordinate>();
        q.add(new Coordinate(x1,y1));
        vis[x1][y1]=true;
        int ctr=0;
        while(!q.isEmpty()){
            int nodesAtCurrBreadth=q.size(); //nodes at curr lvl in BFS
            for(int i=0;i<nodesAtCurrBreadth;i++){
                Coordinate currpos=q.remove();
                if(currpos.x==x2 && currpos.y==y2){
                    return ctr;
                }
                for(int j=0;j<8;j++){
                    int nrow=currpos.x+dx[j];
                    int ncol=currpos.y+dy[j];
                    if(isValid(nrow,ncol,n) && vis[nrow][ncol]==false){
                        q.add(new Coordinate(nrow,ncol));
                        vis[nrow][ncol]=true;
                    }
                }
            }
            ctr++;
        }
        return -1;
    }
    public boolean isValid(int x,int y,int n){
        if(x<=0||y<=0||x>n||y>n){
            return false;
        }
        return true;
    }
    class Coordinate{
        int x,y;
        public Coordinate(int x,int y){
            this.x=x;
            this.y=y;
        }
    }
}
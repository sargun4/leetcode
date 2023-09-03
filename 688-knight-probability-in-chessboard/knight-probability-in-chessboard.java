import java.util.HashMap;

class Solution {
    private int[][] dirn={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    public double knightProbability(int n, int k, int r, int c) {
        HashMap<String,Double> hm=new HashMap<>();
        return find(n,k,r,c,hm);
    }
    public double find(int n, int k, int r, int c,HashMap<String,Double> hm) {
        if(isvalid(r,c,n)==false) return 0;
        if(k==0) return 1;
        String key=r+","+c+","+k;
        if(hm.containsKey(key)) return hm.get(key);
        double prob=0;
        for(int i=0;i<dirn.length;i++){
            prob+=find(n,k-1,r+dirn[i][0],c+dirn[i][1],hm)/8.0;
        }
        hm.put(key,prob);
        return prob;
    }
    private boolean isvalid(int r, int c,int n){
        if(r<0||r>=n||c<0||c>=n) return false;
        return true;
    }
}

//tle
// class Solution {
//     private int[][] dirn={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
//     public double knightProbability(int n, int k, int r, int c) {
//         return find(n,k,r,c);
//     }
//     public double find(int n, int k, int r, int c) {
//         if(isvalid(r,c,n)==false) return 0;
//         if(k==0) return 1;
//         double prob=0;
//         for(int i=0;i<dirn.length;i++){
//             prob+=find(n,k-1,r+dirn[i][0],c+dirn[i][1])/8.0;
//         }
//         return prob;
//     }
//     private boolean isvalid(int r, int c,int n){
//         if(r<0||r>=n||c<0||c>=n) return false;
//         return true;
//     }
// }
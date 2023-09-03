import java.util.HashMap;

class Solution {
    public int minFallingPathSum(int[][] A) {
        int r=A.length;
        int c=A[0].length;
        int ans=Integer.MAX_VALUE;
        HashMap<String,Integer> hm=new HashMap<>();
        
        for(int i=0;i<c;i++){
            ans=Math.min(ans,rec(0,i,A,hm));
        }
        return ans;
    }
    private static int rec(int i,int j,int A[][],HashMap<String,Integer> hm){
        int r=A.length;
        int c=A[0].length;
        if(i==r){
            return 0;
        }
        if(j<0||j>=c) return Integer.MAX_VALUE;

        String key=i+"_"+j;
        if(hm.containsKey(key))
            return hm.get(key);

        int path1=rec(i+1, j-1, A,hm);
        int path2=rec(i+1, j, A,hm);
        int path3=rec(i+1, j+1, A,hm);
        hm.put(key,A[i][j]+Math.min(path1,Math.min(path2, path3)));
        return A[i][j]+Math.min(path1,Math.min(path2, path3));
    } 
}
//tle
// class Solution {
//     public int minFallingPathSum(int[][] matrix) {
//         int r=matrix.length;
//         int c=matrix[0].length;
//         int ans=Integer.MAX_VALUE;
//         for(int i=0;i<c;i++){
//             ans=Math.min(ans,rec(0,i,matrix));
//         }
//         return ans;
//     }
//     private static int rec(int i,int j,int matrix[][]){
//         int r=matrix.length;
//         int c=matrix[0].length;
//         if(i==r){
//             return 0;
//         }
//         if(j<0||j>=c) return Integer.MAX_VALUE;

//         int path1=rec(i+1, j-1, matrix);
//         int path2=rec(i+1, j, matrix);
//         int path3=rec(i+1, j+1, matrix);
//         return matrix[i][j]+Math.min(path1,Math.min(path2, path3));
//     } 
// }
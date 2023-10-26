class Solution {
    //O(n)
    public int getWinner(int[] arr, int k) {
        int winner=arr[0];
        int wincount=0;
        for(int i=1;i<arr.length;i++){
            if(winner>arr[i]){
                wincount++;
            }else{
                winner=arr[i];
                wincount=1;
            }
            if(wincount==k){
                return winner;
                }
        }
        return winner;
    }
}
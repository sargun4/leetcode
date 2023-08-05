class Solution {
     public int snakesAndLadders(int[][] board) {
      int n = board.length;
        int steps = 0;
      Queue<Integer> q = new LinkedList<Integer>();
      boolean visited[][] = new boolean[n][n];
       q.add(1);
       visited[n-1][0] = true;
       while(!q.isEmpty()){
         int size = q.size();
          for(int i =0; i <size; i++){
              int x = q.poll();
              if(x == n*n) return steps;
              for(int k=1; k <=6; k++){
                  if(k+x > n*n) break;
                  int pos[] = findCoordinates(k+x, n);
                  int r = pos[0];
                  int c = pos[1];
                  if(visited[r][c] == true) continue;
                  visited[r][c] = true;
                  if(board[r][c] == -1){
                      q.add(k+x);
                  }else{
                      q.add(board[r][c]);
                  }
              }
          }
        steps++;
      }    
        return -1;
    }
   public int[] findCoordinates(int curr, int n) {
        int r = n - (curr - 1) / n  -1;
        int c = (curr - 1) % n;
        if (r % 2 == n % 2) {
            return new int[]{r, n - 1 - c};
        } else {
            return new int[]{r, c};
        }
    }
}
// import java.util.LinkedList;
// import java.util.Queue;

// class Solution {
//     public int snakesAndLadders(int[][] board) {
//         int n = board.length;
//         Queue<Integer> queue = new LinkedList<>();
//         queue.offer(1);
//         boolean[] visited = new boolean[n * n + 1];
//         for (int move = 0; !queue.isEmpty(); move++) {
//             for (int size = queue.size(); size > 0; size--) {
//                 int num = queue.poll();
//                 if (visited[num]) continue;
//                 visited[num] = true;
//                 if (num == n * n) return move;
//                 for (int i = 1; i <= 6 && num + i <= n * n; i++) {
//                     int next = num + i;
//                     int value = getBoardValue(board, next);
//                     if (value > 0) next = value;
//                     if (!visited[next]) queue.offer(next);
//                 }
//             }
//         }
//         return -1;
//     }
//     private int getBoardValue(int[][] board, int num) {
//         int n = board.length;
//         int r = (num - 1) / n;
//         int x = n - 1 - r;
//         int y = r % 2 == 0 ? num - 1 - r * n : n + r * n - num;
//         return board[x][y];
//     }
// }


// class Solution {
//     int length = 1;
//     int [][] board;
//     public int snakesAndLadders(int[][] board) {
//         this.board = board;
//         length = board.length;
//         HashMap<Integer,Integer> visited = new HashMap();
//         visited.put(1,0);
//         Queue<Integer> arr = new LinkedList<>();
//         arr.add(1);
//         while (!arr.isEmpty()){
//             int n = arr.remove();
//             for(int i = n+1;i<=n+6;i++){
//                 int next = i;
//                 int nextPos = getPosition(i);
//                 if(next>length*length) return -1;
//                 if(nextPos!=-1){
//                     next = nextPos;
//                 }
//                 if(next==length*length) return visited.get(n)+1;
//                 if(!visited.containsKey(next)){
//                     visited.put(next,visited.get(n)+1 );
//                      arr.add(next);
//                 }   
//             }
            
//         }
//         return -1;
//     }

//     public int getPosition(int n){
//         int row = (n-1)/length;
//         int column = (n-1)%length;
//         if(row%2!=0){
//             column = (column-length+1)*-1;
//         }
//         row = (row-length+1)*-1;
        
//         int  result = board[row][column];
//         return result;
//     }
// }
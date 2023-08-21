class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newcolor) {
        if(newcolor==image[sr][sc]) return image;
        dfs(image,sr,sc,newcolor,image[sr][sc]);
        return image;
    }
    private void dfs(int[][] image, int row, int col, int color,int oldcolor){
        if(row>=image.length||row<0||col>=image[0].length||col<0||image[row][col]!=oldcolor) return;
        image[row][col]=color;
        dfs(image, row-1, col, color, oldcolor);
        dfs(image, row+1, col, color, oldcolor);
        dfs(image, row, col-1, color, oldcolor);
        dfs(image, row, col+1, color, oldcolor);
    }
}
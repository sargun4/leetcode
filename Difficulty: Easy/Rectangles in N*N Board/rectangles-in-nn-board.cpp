
class Solution {
public:
    long long rectanglesInChessBoard(long long N){
       ///Total number of squares =
        ///m x (m+1) x (2m+1)/6 + 
        ///(n-m) x m x (m+1)/2 
        //when n is larger dimension. (in n*m grid)
        
        ///and rectangles : M(M+1)(N)(N+1)/4
        //in n*m grids
        //return those rectangles which are not squares
        long long total = N*N*(N+1)*(N+1)/4;
        long long sqr = N*(N+1)*(2*N+1)/6;
        return total-sqr;
    }
};
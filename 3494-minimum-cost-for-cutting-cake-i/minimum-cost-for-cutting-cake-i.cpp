class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int x=horizontalCut.size();
        int y=verticalCut.size();
        //sort in dec order
        sort(begin(horizontalCut),end(horizontalCut),greater<int>());
        sort(begin(verticalCut),end(verticalCut),greater<int>());
        int horizpieces=1;
        int vertpieces=1;
        int res=0;
        
        int i=0; int j=0;

        while(i<x && j<y){
            if(horizontalCut[i]>=verticalCut[j]){
                res+=horizontalCut[i]*vertpieces;
                horizpieces++;
                i++;
            }else{
                res+=verticalCut[j]*horizpieces;
                vertpieces++;
                j++;
            }
        }
        while(i<x){
            res+=horizontalCut[i]*vertpieces;
            horizpieces++;
            i++;
        }
        while(j<y){
            res+=verticalCut[j]*horizpieces;
            vertpieces++;
            j++;
        }
        return res;
    }
};
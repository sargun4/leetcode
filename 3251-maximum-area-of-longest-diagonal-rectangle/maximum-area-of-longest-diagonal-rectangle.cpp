class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea=0; int maxdiag=0;
        for(auto &dim:dimensions){
            int l=dim[0]; int w=dim[1];
            int diag=pow(l,2)+pow(w,2);
            int area=l*w;
            if(maxdiag<diag){
                maxdiag=diag;
                maxarea=area;
            }else if(diag==maxdiag){
                maxarea=max(area,maxarea);
            }
        }
        return maxarea;
    }
};
class Solution {
public:
    int m,n;
    int OneDArrCtr(vector<int>&vec){
        int consec=0;//consec 1s ctr;
        int subctr=0;//consec subarr ctr;
        for(int &val:vec){
            if(val==0){
                consec=0;//reset when hitting a 0
            }else{
                consec++;//extend streak of consec 1s
            }
            subctr+=consec;//each new 1 can form a consec subarr
        }
        return subctr;
    }
    int numSubmat(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        int ans=0;//total no of submats hving only 1s
        for(int sr=0;sr<m;sr++){
            vector<int> vec(n,1);
            for(int er=sr;er<m;er++){
                for(int col=0;col<n;col++){
                    vec[col]=vec[col] & mat[er][col];
                }
                ans+=OneDArrCtr(vec);
            }
        }
        return ans;
    }
};
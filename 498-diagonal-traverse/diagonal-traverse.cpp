class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> res;
        //for any element mat[i][j], the diag it belongs to is uniquely determined by (i + j).
        map<int,vector<int>> mp; //{diag_idx:{num1,num2...}}
        //fill the map using =i+j
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        //map= {{0:{1},1:{2,4},2:{3,5,7},3:{6,8},4:{9}}};
        bool flip=true;
        for(auto &it:mp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            for(int &num:it.second){
                res.push_back(num);
            }
            flip=!flip;//flip dirn fr zig zag
        }
        return res;
    }
};
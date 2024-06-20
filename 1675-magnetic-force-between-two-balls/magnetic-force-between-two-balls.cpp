class Solution {
public:
    bool possibletoplace(int force,vector<int>& position, int m){
        int prev=position[0];
        int ctr=1;
        for(int i=1;i<position.size();i++){
            int curr=position[i];
            if(curr-prev>=force){
                ctr++;
                prev=curr;
            }
            if(ctr==m) break;
        }
        return ctr==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(begin(position),end(position));
        int minforce=1; //l
        int maxforce=position[n-1]-position[0];//r
        int res=0;
        while(minforce<=maxforce){ //l<=r
            int midforce=(minforce+maxforce)/2;
            if(possibletoplace(midforce,position,m)){
                res=midforce;
                minforce=midforce+1;
            }else{
                maxforce=midforce-1;
            }
        }
        return res;
    }
};
class Solution {
public:
    int K;
    vector<long long> power;
    unordered_map<string,int> map;
    int solve(int i,int jump,int cangoback){
        if(i>K+1) return 0; //cant return 
        string key=to_string(i)+"_"+to_string(jump)+"_"+to_string(cangoback);
        if(map.find(key)!=map.end()){
            return map[key];
        }

        int ways=0;
        
        if(i==K) ways+=1;

        if(cangoback==1){
            ways+=solve(i-1,jump,0); //i-1
        }
        ways+=solve(i+power[jump],jump+1,1); //1+2^jump
        return map[key]=ways;
    }
    int waysToReachStair(int k) {
        K=k;
        power.resize(32);
        map.clear();
        for(int i=0;i<=31;i++){
            power[i]=pow(2,i);
        }
        return solve(1,0,1);
    }
};
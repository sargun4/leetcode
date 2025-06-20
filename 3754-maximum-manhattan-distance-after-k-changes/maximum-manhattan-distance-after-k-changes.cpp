class Solution {
public:
    int maxDistance(string s, int k) {
        int maxdist=0;
        int east=0;
        int west=0;
        int north=0;
        int south=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='E') east++;
            else if(s[i]=='W') west++;
            else if(s[i]=='N') north++;
            else if(s[i]=='S') south++;

            int currMD=abs(east-west)+abs(north-south);
            int steps=i+1;
            int wasted=steps-currMD;
            int extrasteps=0;
            if(wasted!=0){//steps !=currMD
                extrasteps=min(2*k,wasted);
            }
            int finalcurrMD=currMD+extrasteps;
            maxdist=max(maxdist,finalcurrMD);
        }
        return maxdist;
    }
};
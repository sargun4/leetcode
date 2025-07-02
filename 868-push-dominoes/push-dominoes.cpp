class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.length();
        vector<int> rightClosestL(n);//stores domino idxs that r on right of domino at idx i that push it towards the L;
        vector<int> leftClosestR(n);//stores domino idxs that r on left of domino at idx i that push it towards the R;
        //move frm L to R to find leftClosestR
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                leftClosestR[i]=i;//R push starts here
            }else if(dominoes[i]=='.'){//check nearest 
                leftClosestR[i]= i>0 ? leftClosestR[i-1] : -1;
            }else{//pushes L,so dnot consider
                leftClosestR[i]=-1;
            }
        }
        //move frm R to L to find rightClosestL
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                rightClosestL[i]=i;//L push starts here
            }else if(dominoes[i]=='.'){//check nearest 
                rightClosestL[i]= i<n-1 ? rightClosestL[i+1] : -1;
            }else{//pushes R,so dnot consider
                rightClosestL[i]=-1;
            }
        }

        string res(n,' ');//str of len n w each char space
        for(int i=0;i<n;i++){
            int distRightL=abs(i-rightClosestL[i]);//dist of domino on RHS of curr domino i pushing it towards L;
            int distLeftR=abs(i-leftClosestR[i]);//dist of domino on LHS of curr domino i pushing it towards R;
            if(leftClosestR[i]==rightClosestL[i]){//both are -1
                res[i]='.';
            }else if(rightClosestL[i]==-1){//no push towards L from RHS of curr domino at i
                res[i]='R';
            }else if(leftClosestR[i]==-1){//no push towards R from LHS of curr domino at i
                res[i]='L';
            }else if(distRightL==distLeftR){//equal force frm each side- so domino at idx i doesnt fall
                res[i]='.';
            }else{
                if(distRightL<distLeftR){//L pushing domino is closer than R pushin
                    res[i]='L';
                }else{//R pushing domino is closer than L pushin
                    res[i]='R';
                }
            }
        }
        return res;
    }
};
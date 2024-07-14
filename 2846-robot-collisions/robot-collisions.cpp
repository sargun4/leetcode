class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> actualidx(n);
        for(int i=0;i<n;i++){
            actualidx[i]=i;
        }
        auto lambda=[&](int &i,int&j){
            return positions[i]<positions[j];
        };
        sort(begin(actualidx),end(actualidx),lambda);
        vector<int> res;
        stack<int> st; //to store actual idx
        for(int &curridx:actualidx){
            if(directions[curridx]=='R'){
                st.push(curridx);
            }else{ //'L'
                while(!st.empty() && healths[curridx]>0){
                    int topidx=st.top();
                    st.pop();
                    if(healths[topidx]>healths[curridx]){
                        healths[topidx]-=1; //dec by 1
                        healths[curridx]=0; //weaker removed frm line
                        st.push(topidx);
                    }else if(healths[topidx]<healths[curridx]){
                        healths[curridx]-=1; //dec by 1
                        healths[topidx]=0; //weaker removed frm line
                    }else{ //if equal healths,both remvoed frm line
                        healths[curridx]=0; 
                        healths[topidx]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                res.push_back(healths[i]);
            }
        }
        return res;
    }
};
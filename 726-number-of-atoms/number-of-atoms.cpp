class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.length();
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>()); 
        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }else if(formula[i]==')'){//pop
                unordered_map<string,int> curr=st.top(); //map at top;
                st.pop();
                i++;
                string mult;
                while((i<n) && isdigit(formula[i])){
                    mult.push_back(formula[i]);
                    i++;
                }
                if(!mult.empty()){
                    int multint=stoi(mult);
                    for(auto &it:curr){
                        string elmnt=it.first;
                        int ctr=it.second;
                        curr[elmnt]=ctr*multint;
                    }
                }
                //merge this to stack's top map
                for(auto &it:curr){
                    string elmnt=it.first;
                    int ctr=it.second;
                    st.top()[elmnt]+=ctr;
                }
            }
            else{
                string currelmnt;
                currelmnt.push_back(formula[i]);//He,Mg
                i++;
                while(i<n  && isalpha(formula[i]) && islower(formula[i])){
                    currelmnt.push_back(formula[i]);//
                    i++;
                }
                string currctr;
                while(i<n && isdigit(formula[i])){
                    currctr.push_back(formula[i]);
                    i++;
                }
                int currctrint=currctr.empty()? 1:stoi(currctr);
                st.top()[currelmnt]+=currctrint;
            }
        }
        string res;
        map<string,int> sortedmap(begin(st.top()),end(st.top()));
        for(auto &it:sortedmap){
            string elmnt=it.first;
            res+=elmnt;
            int ctr=it.second;
            if(ctr>1){
                res+=to_string(ctr);
            }
        }
        return res;
    }
};
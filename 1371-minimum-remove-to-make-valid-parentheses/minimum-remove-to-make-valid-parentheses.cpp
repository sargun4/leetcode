class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<int> st;
        unordered_set<int> removeidx;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                if(st.empty()){//unbalanced closed brkt
                    removeidx.insert(i);
                }else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){//for only open brackts
            removeidx.insert(st.top());
            st.pop();
        }
        string res="";
        for(int i=0;i<n;i++){
            if(removeidx.find(i)==removeidx.end()){//if not presnt
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
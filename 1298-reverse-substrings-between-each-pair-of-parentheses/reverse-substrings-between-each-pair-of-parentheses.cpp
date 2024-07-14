class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> lastskiplen;
        string res;
        for(char &ch:s){
            if(ch=='('){
                lastskiplen.push(res.length());
            }else if(ch==')'){
                int l=lastskiplen.top();
                lastskiplen.pop();
                reverse(begin(res)+l,end(res));
            }else{
                res.push_back(ch);
            }
        }
        return res;
    }
};
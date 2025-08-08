class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxlen=0;
        int n=s.length();
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c == '(') {
                st.push(i); //push the index of the '(' into stack
            }else{
                st.pop(); //pop the top index as we found a matching ')'
                if(st.empty()) {
                    st.push(i); //push the current index as a new base if stack is empty
                }else{
                    int len=i-st.top();//len of the curr valid substring
                    maxlen = max(maxlen,len);
                }
            }
        }
        return maxlen;
    }
};
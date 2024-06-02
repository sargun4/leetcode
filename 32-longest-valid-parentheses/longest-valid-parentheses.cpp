class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxi=0;
        int n=s.length();
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c == '(') {
                st.push(i); // Push the index of the '(' into stack
            }else{
                st.pop(); // Pop the top index as we found a matching ')'
                if(st.empty()) {
                    st.push(i); // Push the current index as a new base if stack is empty
                }else{
                    int len = i - st.top();//length of the current valid substring
                    maxi = max(maxi, len);
                }
            }
        }
        return maxi;
    }
};
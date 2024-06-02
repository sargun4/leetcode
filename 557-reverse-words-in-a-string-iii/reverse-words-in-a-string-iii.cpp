#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        stack<char> st;
        for (char c : s) {
            if (c != ' ') {
                st.push(c);
            } else {
                while (!st.empty()) {
                    result += st.top();
                    st.pop();
                }
                result += ' '; //space after revesing a word
            }
        }
        while (!st.empty()) {
            result += st.top(); 
            st.pop();
        }
        return result;
    }
};

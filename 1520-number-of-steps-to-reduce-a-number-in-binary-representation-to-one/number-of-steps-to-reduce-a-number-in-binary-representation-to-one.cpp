// class Solution {
// public:
// int bintodec(string bin) {
//     int deci = 0;
//     for (char digit : bin) {
//         deci = deci * 2 + (digit - '0');
//     }
//     return deci;
// }

//     int numSteps(string s) {
//         int n=bintodec(s);
//         int ctr=0;
//         while(n!=1){
//             if(n%2==0){
//                 n=n/2;
//             }else{
//                 n++;
//             }
//             ctr++;
//         }
//         return ctr;
//     }
// };
class Solution {
public:
    int numSteps(string s) {
        int res = 0, carry = 0;
        stack<int> st;
        for (auto& digit : s)
            st.push(digit - '0');
        while (st.size() != 1) {
            int curr = st.top();
            st.pop();
            if (curr == 0 and carry == 0)
                res += 1;
            else if (curr == 1 and carry == 0) {
                carry = 1;
                res += 2;
            } else if (curr == 0 and carry)
                res += 2;
            else
                res += 1;
        }
        if (st.top() == 1 and carry)
            res += 1;
        return res;
    }
};
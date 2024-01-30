#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        auto isSign = [](string token) {
            return (token == "+" || token == "-" || token == "*" || token == "/");
        };
        for (auto token : tokens) {
            if (isSign(token)) {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                if (token == "+") {
                    s.push(num1 + num2);
                } else if (token == "-") {
                    s.push(num1 - num2);
                } else if (token == "*") {
                    s.push(num1 * num2);
                } else if (token == "/") {
                    s.push(num1 / num2);
                }
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};

class Solution {
  public:
    bool isBalanced(string& k) {
        stack<char> s;
        for(char it:k){
            if(it=='(' or it=='[' or it=='{'){
                s.push(it);
            }
            else{
                if(it==')'){
                    if(s.empty() or s.top()!='('){
                        return false;
                    }
                }if(it=='}'){
                    if(s.empty() or s.top()!='{'){
                        return false;
                    }
                }if(it==']'){
                    if(s.empty() or s.top()!='['){
                        return false;
                    }
                }
                s.pop();
            }
        }
        return s.empty();
    }
};
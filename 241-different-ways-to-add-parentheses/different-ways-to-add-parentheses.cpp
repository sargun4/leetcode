class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        if(expression==""){//if str is empty,then return empty list
            return ans;
        }
        int n=expression.length();
        if(n==1){//only a single char in str
            int num=stoi(expression);
            ans.push_back(num);
            return ans;
        }
        if(n==2 && isdigit(expression[0])){//if str has only 2 chars n 1st is digit
            int num=stoi(expression);
            ans.push_back(num);
            return ans;
        }
        //rec
        for(int i=0;i<n;i++){//go over all chars
            char currChar=expression[i];
            if(isdigit(currChar)){//skip if alr a digit
                continue;
            }
            string lsubstr=expression.substr(0,i);
            string rsubstr=expression.substr(i+1);
            vector<int> leftRes=diffWaysToCompute(lsubstr);
            vector<int> rightRes=diffWaysToCompute(rsubstr);
            //combine res frm l n r parts
            for(int l:leftRes){
                for(int r:rightRes){
                    int res=0;
                    switch(currChar){
                        case '+':
                            res=l+r;
                            break;
                        case '-':
                            res=l-r;
                            break;
                        case '*':
                            res=l*r;
                            break;
                    }
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};
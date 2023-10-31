class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        a,n=[],len(tokens)
        for i in range(n):
            if tokens[i]=='+' or tokens[i]=='-' or tokens[i]=='*' or tokens[i]=='/':
                x=int(a.pop())
                y=int(a.pop())
                if tokens[i]=='+':
                    a.append(y+x)
                elif tokens[i]=='-':
                    a.append(y-x)
                elif tokens[i]=='*':
                    a.append(y*x)
                else:
                    a.append(y/x)
            else:
                a.append(tokens[i])
        return int(a[0])
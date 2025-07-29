class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int shortestPath(int num1, int num2) {
        string s1=to_string(num1);
        string s2=to_string(num2);
        queue<pair<string,int>> q;//{str:steps}
        vector<int> vis(1e5,0);
        q.push({s1,0});
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            int steps=curr.second;
            string s=curr.first;
            int no=stoi(s);
            vis[no]=1;//mark this no as vis
            if(s==s2){//reached final string
                return steps;
            }
            //try changing all 4 chars of s to get the num, if its prime,n not yet vis;
            // push into q 
            for(int i=0;i<4;i++){
                char temp=s[i];//store the char being changed 
                for(int j=0;j<10;j++){
                    if(i==0 && j==0){
                        continue;
                    }
                    s[i]=char(j+'0');
                    int num=stoi(s);
                    //if num is prime & not yet vis;
                    if(isPrime(num) && !vis[num]){
                        q.push({s,steps+1});
                        vis[num]=1;
                    }
                }
                s[i]=temp;//revert back to the original char
            }
        }
        return -1;//unreachable
    }
};

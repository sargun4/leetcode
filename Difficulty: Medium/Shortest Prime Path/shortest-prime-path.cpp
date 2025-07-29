class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int solve(int num1, int num2) {
        string s1=to_string(num1);
        string s2=to_string(num2);
        vector<int> vis(1e5,0);
        queue<pair<string,int>> q;//{str,mindist}
        q.push({s1,0});
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            string s=curr.first;
            int steps=curr.second;
            int no=stoi(s);
            
            vis[no]=1;//mark the number formed visited
            
            if(s==s2){//reahed our final str
                return steps;
            }
            // str size 4 always
            for(int i=0;i<4;i++){
                char temp=s[i];
                for(int j=0;j<10;j++){
                    if(i==0 && j==0){
                        continue;
                    }
                    s[i]=char(j+'0');
                    int num=stoi(s);
                    if(isPrime(num) && !vis[num]){
                        q.push({s,steps+1});
                        vis[num]=1;
                    }
                }
                s[i]=temp;//get that char back
            }
        }
        return -1;
    }
};

typedef long long ll;
class Solution {
public:
    bool isPrime(ll num){
        if(num<=1) return false;
        if (num == 2) return true;
        for(ll i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        // string substr
        int n=s.size();
        unordered_set<ll> uniquePrimes;
        for(int i=0;i<n;i++){
            for(int j=1;j<=n-i;j++){
                string sub=s.substr(i,j);
                //remove leading 0s
                int pos=0;
                while(pos<sub.size() && sub[pos]=='0'){
                    pos++;
                }
                // skip "000..." which becomes empty or 0
                if(pos==sub.size()) continue;

                ll num=stoll(sub.substr(pos));
                if(isPrime(num)){
                    uniquePrimes.insert(num);
                }
            }
        }
        if(uniquePrimes.empty()) return 0;
        //set to vector and sort in desc
        vector<ll> primes(uniquePrimes.begin(), uniquePrimes.end());
        sort(primes.begin(), primes.end(), greater<ll>());

        //sum top 3 largest primes or fewer
        ll sum = 0;
        for (int i = 0; i < min(3, (int)primes.size()); ++i) {
            sum += primes[i];
        }

        return sum;
    }
};
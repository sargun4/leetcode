class Solution {
  public:
    long long int minSum(int arr[], int n){
        sort(arr,arr+n);
        long long n1=0,n2=0;
        for(int i=0;i<n;i+=2){
            n1=n1*10 + arr[i];
        }
         for(int i=1;i<n;i+=2){
            n2=n2*10 + arr[i];
        }
        return n1+n2;
    }
};
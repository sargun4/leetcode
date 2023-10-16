#include <bits/stdc++.h>
using namespace std; 
// class Solution {
// public:
//     int trap(vector<int>& height) {        
//         int n = height.size(); 
//         int left=0; int right=n-1;
//         int res=0;
//         int maxleft=0, maxright=0;
//         while(left<=right){
//             if(height[left]<=height[right]){
//                 if(height[left]>=maxleft) maxleft=height[left];
//                 else res+=maxleft-height[left];
//                 left++;
//             }
//             else{
//                 if(height[right]>=maxright) maxright= height[right];
//                 else res+=maxright-height[right];
//                 right--;
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> getLeftMaxArr(vector<int>& height,int &n){
        vector<int> leftMax(n,0);
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        return leftMax;
    }
    vector<int> getRightMaxArr(vector<int>& height,int &n){
        vector<int> rightMax(n,0);
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        return rightMax;
    }

    int trap(vector<int>& height) {        
       int n=height.size();
       vector<int> leftmax=getLeftMaxArr(height,n);
       vector<int> rightmax=getRightMaxArr(height,n);

       int sum=0;
       for(int i=0;i<n;i++){
           int h=min(leftmax[i],rightmax[i])-height[i];
           sum+=h;
       }
       return sum;
    }
};
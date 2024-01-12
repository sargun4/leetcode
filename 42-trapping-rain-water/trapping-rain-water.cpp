#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {        
        int water=0;
        int n = height.size(); 
        int maxHtleft=0;
        int maxHtright=0;
        vector<int> maxleft(n,0);
        vector<int> maxright(n,0);
        //filling maxleft
        for(int i=0;i<n;i++){
            if(maxHtleft < height[i]){
                maxHtleft = height[i];
            }
            maxleft[i] = maxHtleft;
        }
        //filling maxright
        for(int i=n-1;i>=0;i--){
            if(maxHtright < height[i]){
                maxHtright = height[i];
            }
            maxright[i] = maxHtright;
        }
        for(int i=0;i<n;i++){//O(n)
            int temp = min(maxleft[i],maxright[i]) - height[i];
            water = water+((temp>0)?temp:0);
        }
        return water;
    }
}; 
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
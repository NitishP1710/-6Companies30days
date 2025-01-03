#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
    int i,j,k,ans=0,n=nums.size();
    for(i=0;i<nums.size();i++){
        for(j=i;j<nums.size();j++){
            int flag=0;
            k=0;
            if(i==0) k=j+1;
            while(k<n-1){
                if(k==i-1 && j+1<n && nums[k]>=nums[j+1]) flag=1;
                else if(k<i-1 && nums[k]>=nums[k+1]) flag=1;
                else if(k>j && k+1<n && nums[k]>=nums[k+1]) flag=1;
                if(flag==1) {break;} 
                k++;
            }
            if(flag==0) ans++;
        }
    }
    return ans;  
    }
};

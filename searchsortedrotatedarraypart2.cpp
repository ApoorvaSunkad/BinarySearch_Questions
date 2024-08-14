/*
There is an integer array nums sorted in non-decreasing order 
(not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k 
(0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], 
nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be 
rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, 
or false if it is not in nums.

You must decrease the overall operation steps as much as possible.


Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

*/

//Brute force:
//T.C = O(N)
//S.C = O(1)

#include<iostream>
#include<vector>
using namespace std;
bool search(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i<n;i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
}

//Optimal solution:
//T.C = O(LOGN)
//S.C = O(1)

//solution is expalined by CodestorywithMIK.

int binarySearch(int start, int end, vector<int>&nums,int target){
    int low = start, high = end;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] == target){
            return mid;
        }else if(nums[mid]>target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}
int findPivot(vector<int>&nums,int n){
    int l = 0, r = n-1;
    while(l<r){
        int mid = l+(r-l)/2;
        if(nums[mid]>nums[r]){
            l = mid+1;
        }else{
            r=mid;
        }
    }
    return r;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();

    int pivot_idx = findPivot(nums,n);
    int idx = binarySearch(0,pivot_idx-1,nums,target);
    if(idx!=-1){
        return idx;
    }
    idx = binarySearch(pivot_idx,n-1,nums,target);
    return idx;
}
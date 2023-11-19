/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/

//Optimal solution:

#include<bits/stdc++.h>
using namespace std;

int firstOccur(vector<int>& nums, int target){

        int n = nums.size();

        int low = 0, high = n-1;
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]==target){
                ans = mid;
                high = mid - 1;
            }
            else if(target>nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            mid = low + (high - low) / 2;
        }
        return ans;
}

int lastOccur(vector<int>& nums, int target){

    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1;

        while (low <= high) {
           int mid = low + (high - low) / 2;

           if (nums[mid] == target) {
              ans = mid;
              low = mid + 1; // Move to the right to find the ending position
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            mid = low + (high - low) / 2;
        }
        return ans;
}
vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> v{-1,-1};
        v[0] = firstOccur(nums,target);
        v[1] = lastOccur(nums,target);

        return v;
}
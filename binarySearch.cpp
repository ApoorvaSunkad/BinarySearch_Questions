/*
Given an array of integers nums which is sorted in ascending order, and an integer 
target, write a function to search target in nums. If target exists, then return its index. 
Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1.

*/

//Iterative code:
//T.C = O(LogN)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;

        int mid = start +(end-start)/2;

        while(start<=end){
            if(target==nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                start = mid+1;
            }else{
                end = mid-1;
            }
            mid = start +(end-start)/2;
        }
        return -1;
}

//Recurisive code:
int binarySearchRecursive(vector<int>& nums, int low, int high, int target){
    //base case
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;

    if(target == nums[mid]){
        return mid;
    }
    else if(target > nums[mid]){
        return binarySearchRecursive(nums,mid+1,high,target);
    }
    return binarySearchRecursive(nums,low,high-1,target);
}

int search(vector<int>& nums, int target) {
        return binarySearchRecursive(nums,0,nums.size()-1,target);
}

//Time complexity:

// O(LogN)
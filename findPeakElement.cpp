/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always 
considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, 
or index number 5 where
the peak element is 6.

*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

//Brute force approach:

int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n;i++){
            if((i==0 || nums[i-1]<nums[i]) && (i==n-1 || nums[i]>nums[i+1])){
                return i;
            }
        }
        return 0;
}

//Optimised approach: Look striver's video for explaination
//T.C = O(LOGN)
//S.C = O(1)

int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }

        int low = 1, high = n-2;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){ //peak lies in right half
                low = mid+1;
            }
            else if(nums[mid]>nums[mid+1]){ // peak lies in left half
                high = mid-1;
            }
            else{
                low = mid+1; // if we have multiple peaks then either we can take a peak 
                //from left part or the right part.
            }
        }
        return -1;
}
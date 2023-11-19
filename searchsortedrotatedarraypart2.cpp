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

#include<bits/stdc++.h>
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

//solution is expalined by striver.

#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0, end = n-1;
        while(start<=end){
            int mid = (start+end)/2;

            if(nums[mid]==target){
                return true;
            }
            //below 3 lines are modified lines from previous code.
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start = start+1;
                end = end -1;
                continue;
            }//
            if(nums[start] <= nums[mid]){
                if(nums[start]<= target && target < nums[mid]){
                    end = mid-1;
                }
                else{
                    start = mid + 1;
                }
            }
            else{
                if(nums[mid]<=target && target <= nums[end]){
                    start = mid +1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return false;
}
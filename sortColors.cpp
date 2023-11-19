/*
Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order red, white,
and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

*/

//Brute force:
//T.C = O(N log N)
//S.C = O(1)

//Brute force would be to simply sort the array:
//sort(num.begin(),nums.end());
//return nums;


//Better solution would be to count the number of 0's, 1's, 2's
//and put back them in the original array
//look for striver's video for this better solution

//T.C = O(2N)
//S.C = O(1)

//Optimal solution
//uses the famous algorithm called "DUTCH NATIONAL FLAG ALGORITHM "

//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

//DUTCH NATIONAL FLAG ALGORITHM: Look into GFG article for info.

void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
}


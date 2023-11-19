/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 
1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element 
of this array.

You must write an algorithm that runs in O(log n) time.

*/

//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
        int mini = INT_MAX;

        for(int i = 0; i<nums.size();i++){
            if(nums[i]<mini){
                mini = nums[i];
            }
        }
        return mini;
}

//Optimal solution: using binary search
//T.C = O(LOG N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[low] <= nums[mid]){
                ans = min(ans,nums[low]);
                low = mid+1;
            }
            else{
                high = mid-1;
                ans = min(ans,nums[mid]);
            }
        }
        return ans;
}

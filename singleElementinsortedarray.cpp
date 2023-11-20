/*
You are given a sorted array consisting of only integers where every element appears 
exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.


Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

*/

//Brute force solutions:
//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i = 0; i<n; i++){
            if(i == 0){
                if(nums[i]!=nums[i+1]){
                    return nums[i];
                }
            }
            else if(i == n-1){
                if(nums[i]!=nums[i-1]){
                    return nums[i];
                }
            }
            else{
                if(nums[i]!=nums[i+1] && nums[i]!= nums[i-1]){
                    return nums[i];
                }
            }
        }
        return 0;
}

//2ND Brute force solution
//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        map<int,int> mp;

        for(int i = 0; i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            if(it.second == 1){
                return it.first;
            }
        }
        return 0;
}

//Better solution:
//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        int xorr = 0;

        for(int i = 0; i<nums.size();i++){
            xorr = xorr^nums[i];
        }
        return xorr;
}

//Optimised approach

//T.C = O(LOG N) -> using binary search
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

//Look for striver's video for explaination

int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }

        int low = 1, high = n-2;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]!=nums[mid+1]&& nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            //we are on left
            if((mid % 2 == 1 && nums[mid]==nums[mid-1])||(mid % 2 == 0 && nums[mid]==nums[mid+1])){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
}
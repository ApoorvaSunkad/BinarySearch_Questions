/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median 
of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

//Brute force approach: using the concept of merge 2 sorted arrays

//T.C = O(M+N) => going through every element in both the arrays, "SO MIGHT GET TLE ERROR"
//S.C = O(M+N) => Storing the merged array in a new array

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i=0,j=0;

        vector<int>temp;

        int m=nums1.size(),n=nums2.size();

        while(i<m && j<n){

           if(nums1[i]<=nums2[j])temp.push_back(nums1[i++]);
           else temp.push_back(nums2[j++]);
        }
        while(i<m){
           temp.push_back(nums1[i++]);
        }

        while(j<n){
          temp.push_back(nums2[j++]);
        }

        int k = (m+n);
        
        if(k%2==1){
            return temp[k/2];
        }

        return (double)((double)(temp[k/2])+ (double)(temp[k/2-1]))/2.00;
}

//Better approach:
//Here the T.C will remain same as brute force approach but the space complexity is being reduced to 
//O(1) as we are only using pointers.

//T.C = O(M+N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0, j = 0;

        int n = (n1+n2);

        int index2 = (n/2);
        int index1 = (index2-1);

        int cnt = 0;

        int ind1ele = -1, ind2ele = -1;

        while(i < n1 && j < n2){
            if(nums1[i]<nums2[j]){
                if(cnt == index1) ind1ele = nums1[i];
                if(cnt == index2) ind2ele = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt == index1) ind1ele = nums2[j];
                if(cnt == index2) ind2ele = nums2[j];
                cnt++;
                j++;
            }
        }

        while(i<n1){
            if(cnt == index1) ind1ele = nums1[i];
            if(cnt == index2) ind2ele = nums1[i];
            cnt++;
            i++;
        }
        while(j<n2){
            if(cnt == index1) ind1ele = nums2[j];
            if(cnt == index2) ind2ele = nums2[j];
            cnt++;
            j++;
        }

        if(n%2 == 1){
            return ind2ele;
        }

        return (double)((double)(ind1ele+ind2ele)) / 2.0;
}

//Optimised Approach: Using binary search
//best explained by keerti purswani and also in leetcode discussion section

//T.C = O(log(min(n1,n2))) 
//S.C = O(1)


#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // Ensure nums1 is the smaller array for simplicity
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // Calculate the left partition size
        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high) >> 1; // Calculate mid index for nums1
            int mid2 = left - mid1; // Calculate mid index for nums2
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            // Determine values of l1, l2, r1, and r2
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                // The partition is correct, we found the median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                // Move towards the left side of nums1
                high = mid1 - 1;
            }
            else {
                // Move towards the right side of nums1
                low = mid1 + 1;
            }
        }
        
        return 0; // If the code reaches here, the input array
}
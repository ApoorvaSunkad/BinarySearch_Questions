/*
Given a sorted array arr[] of size n without duplicates, and given a value x. 
Floor of x is defined as the largest element k in arr[] such that k is 
smaller than or equal to x. Find the index of k(0-based indexing).

Examples

Input: n = 7, x = 0 arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less than 0 is found. So output is "-1".
Input: n = 7, x = 5 arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is 2 (i.e k = 2), whose index is 
1(0-based indexing).

Your Task:
The task is to complete the function findFloor() which returns an integer 
denoting the index value of K or return -1 if there isn't any such number.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ n ≤ 107
1 ≤ arr[i] ≤ 1018
0 ≤ x ≤ arr[n-1]

*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(logN)
//S.C = O(1)

int findFloor(vector<long long> v, long long n, long long x){
        
    int res = -1;
    
    long long start = 0, end = n-1;
    while(start<=end){
        
        int mid = start + (end-start)/2;
        
        if(v[mid]==x){
            return mid;
        }
        if(v[mid]<x){
            res = mid;
            start = mid+1;
        }
        else if(v[mid]>x){
            end = mid-1;
        }
    }
    return res;
        
}
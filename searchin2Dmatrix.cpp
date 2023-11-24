/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

*/

//Brute force: would be a simple linear search to search the target

//T.C = O(M*N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i<m;i++){
            for(int j = 0; j<n;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
}

//Optimised solution:
//2 Solutions 

//T.C = O(M+N)
//S.C = O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(); // row
        int n = matrix[0].size(); // col
        int i = 0;
        int j = n - 1;

        while (i >= 0 && i < m && j >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else if (matrix[i][j] < target) {
                i++;
            }
        }

        return false;
}

//T.C = O(LOG M*N)
//S.C = O(1)

//Using binary search please look for striver's video for explaination:
// video link:  https://www.youtube.com/watch?v=JXU4Akft7yk

bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(); // row
        int n = matrix[0].size(); // col
        
        int low = 0, high = (m*n-1);

        while(low<=high){

            int mid = (low+high)/2;

            int row = mid/n, col = mid%n; //These are very important
            //these row and col are hypothetically used by the concept of 1D array

            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
}
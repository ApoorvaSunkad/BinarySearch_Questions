/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent 
neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak 
element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 
in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

*/

//Brute force: Finding the largest element in the 2D Matrix

//T.C = O(M*N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int index1 = -1, index2 = -1;
        vector<int> v;

        int maxi = INT_MIN;

        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(mat[i][j]>maxi){
                    maxi = mat[i][j];
                    index1 = i;
                    index2 = j;
                }
            }
        }
        v.push_back(index1);
        v.push_back(index2);
        return v;
}


//Better solution:

//T.C = O(M*N)
//S.C = O(1)

vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

    // Iterate through each element in the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            bool isPeak = true;

            // Check if mat[i][j] is greater than its adjacent neighbors (if they exist)
            if (i > 0 && mat[i][j] <= mat[i - 1][j]) {
                isPeak = false; // mat[i][j] is not greater than its top neighbor
            }
            if (i < m - 1 && mat[i][j] <= mat[i + 1][j]) {
                isPeak = false; // mat[i][j] is not greater than its bottom neighbor
            }
            if (j > 0 && mat[i][j] <= mat[i][j - 1]) {
                isPeak = false; // mat[i][j] is not greater than its left neighbor
            }
            if (j < n - 1 && mat[i][j] <= mat[i][j + 1]) {
                isPeak = false; // mat[i][j] is not greater than its right neighbor
            }

            // If mat[i][j] is greater than all its neighbors, it is a peak element
            if (isPeak) {
                return {i, j};
            }
        }
    }

    // No peak element found
    return {-1, -1};
}


//Optimal approach: Using binary search
//T.C = O(M*LOG N)
//S.C = O(1)

int maxrowElement(vector<vector<int>>& mat,int m,int n,int col){
    int maxValue = -1;
    int index = -1;

    for(int i = 0; i<m;i++){
        if(mat[i][col]>maxValue){
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = n-1;

        while(low<=high){

            int mid = (low+high)/2;

            int row = maxrowElement(mat,m,n,mid);

            int left = mid-1 >= 0 ? mat[row][mid-1]: -1;
            int right = mid+1 < n ? mat[row][mid+1]: -1;

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
}


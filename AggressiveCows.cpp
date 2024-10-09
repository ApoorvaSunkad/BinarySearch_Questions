/*
You are given an array consisting of n integers which denote the position of a stall.
You are also given an integer k which denotes the number of aggressive cows. 
You are given the task of assigning stalls to k cows such that the minimum distance 
between any two of them is the maximum possible.

Input format:
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5 
k=3
stalls = [1 2 4 8 9]

Output:
3
Explanation:
The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways.
Example 2:

Input:
n=5 
k=3
stalls = [10 1 2 7 5]

Output:
4
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4,
which also is the largest among all possible ways.


*/


//Brute force: Using linear search
//T.C = O(nlogn) + O(max-min)*O(n) == O(N^2)
//S.C = O(1)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool canWePlace(vector<int> &stalls, int dist, int k) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= k) return true;
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        //sort the stalls[]:
       sort(stalls.begin(), stalls.end());

       int limit = stalls[n - 1] - stalls[0];
       for (int i = 1; i <= limit; i++) {
          if (canWePlace(stalls, i, k) == false) {
              return (i - 1);
            }
        }
        return limit;
}

//Optimised solution: Using Binary search

//T.C = O(nlogn)+ O(log[stalls[0]-stalls[n-1]])*O(n)
//S.C = O(1)

#include<iostream>
#include<vector>
using namespace std;

  bool isPossible(vector<int> &stalls, int n, int k, int minAllowedDist){
        
        int cows = 1, lastStallPos = stalls[0];
        for(int i = 1; i<n; i++){
            if(stalls[i]-lastStallPos >= minAllowedDist){
                cows++;
                lastStallPos = stalls[i];
            }
            
            if(k == cows){
                return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int st = 1, end = stalls[n-1]-stalls[0] ,ans = -1;
        
        while(st<=end){
            int mid = st + (end-st)/2;
            if(isPossible(stalls,n,k,mid)){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
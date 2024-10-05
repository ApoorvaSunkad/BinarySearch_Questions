/*
You have n books, each with arr[i] a number of pages. m students 
need to be allocated contiguous books, with each student getting at 
least one book.
Out of all the permutations, the goal is to find the permutation 
where the sum of the maximum number of pages in a book allotted to a 
student should be the minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment 
should be in contiguous order (see the explanation for better understanding).

Examples:

Input: n = 4, arr[] = [12, 34, 67, 90], m = 2
Output: 113
Explanation: Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113, which is selected as the 
output.

Input: n = 3, arr[] = [15, 17, 20], m = 5
Output: -1
Explanation: Allocation can not be done.
Expected Time Complexity: O(n logn)
Expected Auxilliary Space: O(1)

Constraints:
1 <=  n, m <= 105
1 <= arr[i] <= 106 

*/
#include<iostream>
using namespace std;

//T.C = O(N*logN)
//S.C = O(1)

bool isValid(int arr[], int n, int m,int maxAllowedPages){
    int stu = 1, pages = 0;
    for(int i = 0; i<n;i++){
        if(arr[i]>maxAllowedPages){
            return false;
        }
        if(pages +arr[i] <= maxAllowedPages){
            pages+=arr[i];
        }else{
            stu++;
            pages = arr[i];
        }
    }
    return stu > m?false:true;
}
    // Function to find minimum number of pages.
long long findPages(int n, int arr[], int m) {
        
    if(m>n){
        return -1;
    }
    int sum = 0, ans = -1;
    for(int i = 0; i<n; i++){
        sum+=arr[i];
    }
    
    int st = 0, end = sum;
    while(st<=end){
        int mid = st+(end-st)/2;
        
        if(isValid(arr,n,m,mid)){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
    return ans;
}
/*
Given a sorted array arr containing n elements with possibly some duplicate, 
the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.


Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  
6 6
Explanation: 
First and last occurrence of 7 is at index 6.
Your Task:
Since, this is a function problem. You don't need to take any input, as it is already 
accomplished by the driver code. You just need to complete the function find() that 
takes array arr, integer n and integer x as parameters and returns the required answer.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).


*/


//This type of question is already done but this is from GFG (Medium level)

#include<bits/stdc++.h>
using namespace std;

//T.C = O(logN)
//S.C = O(1)

vector<int> find(int arr[], int n , int x )
{
    // code here
    int start = 0, end = n-1;
    int first = -1, last = -1;
    
while(start<=end){

    int mid = start+(end-start)/2;

    if(arr[mid]==x){
        first = mid;
        end = mid-1;
    }
    else if(arr[mid]>x){
        end = mid-1;
    }
    else{
        start = mid+1;
    }
}
    
start = 0, end = n-1;
    
while(start<=end){
    int mid = start+(end-start)/2;
    if(arr[mid]==x){
        last = mid;
        start = mid+1;
    }
    else if(arr[mid]>x){
        end = mid-1;
    }
    else{
        start = mid+1;
    }
}
return {first,last};

}


//Using C++ STL functions of binary search

#include<bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x ){
    
    //binary_search STL function takes 3 parameters that are
    //The starting address of the array
    //The ending address of the array(arr+n) tells that the index considered is the index
    //after the last element
    //an element to search

    //Returns a boolean value depending upon if ele is present or not

    if(!binary_search(arr,arr+n,x)){
        return {-1,-1};
    }
    
    int first = -1, last = -1;
    
    //These Lower bound and upper bound return the iterators 
    //hence if we want indexes then we need to substract the
    //starting address so that the index is returned.

    //Lower bound function always gives the iterator which is 
    //greater than equal to(>=) the element that we are searching.

    //for ex: arr[] = {1,2,2,2,2,3,4}
    //here 2 appears at 1st index and at 4th index in the above array
    //So lower bound function's iterator will have address at start and address 
    //after last element of array and now 2 is found
    //so when we substract arr it gives the index as "1"

    first = lower_bound(arr,arr+n,x)-arr;
    last = upper_bound(arr,arr+n,x)-arr-1;

    //Upper bound function always gives the iterator which is only
    //greater than (>) the element that we are searching.

    //for ex: arr[] = {1,2,2,2,2,3,4}
    //here 2 appears at 4th index in the above array
    //So upper bound function's iterator will have address at start and address 
    //after last element of array. So here the iterator will point to the element 3 but we want 
    //last occurrenc of 2 hence in the upper bound function we substract 1 from the iterator so that 
    //we get the exact index of element 2 and now 2 is found
    //so when we substract arr it gives the index as "4"
    
    return {first,last};
}


//For better understanding watch keerti purswani's video
//Video Link: https://www.youtube.com/watch?v=SnrAclUvgPw&list=PLBsIjVjZHP8pfwgl9tb72lPadnZ_S8U_m&index=4
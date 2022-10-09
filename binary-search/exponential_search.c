
#include <stdio.h>
 
// Utility function to find a minimum of two numbers
int min(int x, int y) {
    return (x < y) ? x : y;
}
 
// Binary search algorithm to return the position of key `x` in subarray A[low…high]
int binarySearch(int A[], int low, int high, int x)
{
    // base condition (search space is exhausted)
    if (low > high) {
        return -1;
    }
 
    // find the mid-value in the search space and
    // compares it with the key
 
    int mid = (low + high)/2;        // overflow can happen
    // int mid = low + (high - low)/2;
 
    // base condition (a key is found)
    if (x == A[mid]) {
        return mid;
    }
 
    // discard all elements in the right search space,
    // including the middle element
    else if (x < A[mid]) {
        return binarySearch(A, low, mid - 1, x);
    }
 
    // discard all elements in the left search space,
    // including the middle element
    else {
        return binarySearch(A, mid + 1, high, x);
    }
}
 
// Returns the position of key `x` in a given array `A` of length `n`
int exponentialSearch(int A[], int n, int x)
{
    // base case
    if (n == 0) {
        return -1;
    }
 
    int bound = 1;
 
    // find the range in which key `x` would reside
    while (bound < n && A[bound] < x) {
        bound *= 2;        // calculate the next power of 2
    }
 
    // call binary search on A[bound/2 … min(bound, n-1)]
    return binarySearch(A, bound/2, min(bound, n - 1), x);
}
 
// Exponential search algorithm
int main(void)
{
    int A[] = {2, 5, 6, 8, 9, 10};
    int target = 9;
 
    int n = sizeof(A)/sizeof(A[0]);
    int index = exponentialSearch(A, n, target);
 
    if (index != -1) {
        printf("Element found at index %d", index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}

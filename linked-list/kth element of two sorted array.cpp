//Problem Link --> https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution{
    public:
    int kth(int *arr1, int *arr2, int *end1, int *end2, int k) 
    { 
        if (arr1 == end1) 
            return arr2[k]; 
        if (arr2 == end2) 
            return arr1[k]; 
        int mid1 = (end1 - arr1) / 2; 
        int mid2 = (end2 - arr2) / 2; 
        if (mid1 + mid2 < k) 
        { 
            if (arr1[mid1] > arr2[mid2]) 
                return kth(arr1, arr2 + mid2 + 1, end1, end2, 
                    k - mid2 - 1); 
            else
                return kth(arr1 + mid1 + 1, arr2, end1, end2, 
                    k - mid1 - 1); 
        } 
        else
        { 
            if (arr1[mid1] > arr2[mid2]) 
                return kth(arr1, arr2, arr1 + mid1, end2, k); 
            else
                return kth(arr1, arr2, end1, arr2 + mid2, k); 
        } 
    } 
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        return kth(arr1, arr2, arr1+n, arr2+m, k-1);
    }
};
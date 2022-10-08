class Solution {
public:
   bool search(vector<int>&a, int l, int r, int key)
{
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(a[mid]==key)  return true;
        else if(a[mid]>key) r=mid-1;
        else    l=mid+1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i=0;i<n;i++)
        if(search(matrix[i],0,m-1,target))  return true;  
    return false;
}
};

//Question link: https://leetcode.com/problems/search-a-2d-matrix/

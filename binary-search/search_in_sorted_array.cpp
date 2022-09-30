int searchInSorted(int a[], int n, int x) {
    int start= 0, end = n-1; 

    while(start <= end){
        int mid = (start+end)/2; 
            
        if(a[mid] == x) {
            return 1; 
        }
            
        else if (a[mid] > x) {
            end = mid-1; 
        }
          
        else 
            start = mid+1; 
    }
        
    return -1; 
}
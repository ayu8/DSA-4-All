int MaxGirlsHeCanImpress(int n, int k)
{
	int girls[n];
	// n -> length of the track
	// k -> max distance he can run
	    for(int i=0;i<n;i++) {
	        cin>>girls[i]; // per 1km
	    }
	    int max = 0;
	    int i=0, j=k-1;
	    while(j<n) {
	        int sum = 0;
	        for(int p=i;p<=j;p++){
	            sum += girls[p];
	        }
	        if(sum > max) {
	            max = sum;
	        }
	        i++; j++;
	    }
	    return max;
}

// question link:
// https://www.codechef.com/problems/PROC18A

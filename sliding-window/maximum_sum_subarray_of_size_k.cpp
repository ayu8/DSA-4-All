long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    // code here
    long sum1 = 0, mx = INT_MIN;

    int i = 0, j = 0;

    while (j < N)
    {
        sum1 += Arr[j];

        if (j - i + 1 == K)
        {
            mx = max(mx, sum1);
            sum1 = sum1 - Arr[i];
            i++;
        }

        j++;
    }

    return mx;
}


// question link :
// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
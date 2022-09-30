int minJumps(int arr[], int n)
{
    // Your code here

    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;

    int maxReachable = arr[0];
    int jumps = 1;
    int steps = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jumps;

        maxReachable = max(maxReachable, i + arr[i]);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= maxReachable)
                return -1;
            steps = maxReachable - i;
        }
    }

    return -1;
}
int setBits(int N)
{
    // Write Your Code here
    int count = 0;
    while (N)
    {
        N = N & (N - 1);
        count++;
    }
    return count;
}
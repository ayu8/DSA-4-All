long long toh(int N, int from, int to, int aux)
{
    // Your code here
    long long count = 0;
    if (N == 1)
    {
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        count = 1;
        return count;
    }

    count += toh(N - 1, from, aux, to);
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    count++;
    count += toh(N - 1, aux, to, from);
    return count;
}

// question link : 
// https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
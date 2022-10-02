// QUESTION LINK :
// https://www.codechef.com/submit/MTYFRI

void solve()
{
    int n, k;
    cin >> n >> k;
    int bsize = ceil((float)n / 2);
    int csize = n - bsize;
    int *A = new int[n]{0};
    int *B = new int[bsize]{0};
    int *C = new int[csize]{0};
    int b = 0, c = 0;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        i % 2 == 0 ? B[b++] = A[i] : C[c++] = A[i];
    }
    sort(B, B + bsize, greater<int>());
    sort(C, C + csize);
    int minswap = min(csize, k);
    for (int i = 0; i < minswap; i++)
    {
        if (B[i] > C[i])
        {
            swap(B[i], C[i]);
        }
    }
    sum1 = accumulate(B, B + bsize, sum1);
    sum2 = accumulate(C, C + csize, sum2);
    sum2 > sum1 ? cout << "YES" << endl : cout << "NO" << endl;
}
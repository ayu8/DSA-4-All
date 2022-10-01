// A really intersting question on bit manipulation
// Question Link : https://www.codechef.com/submit/XORNEY?tab=statement

void solve()
{
    long long int l, r;
    cin >> l >> r;
    long long int k = r - l + 1;
    if ((l & 1) == 0)
    {
        k = k >> 1;
    }
    else
    {
        k = (k + 1) >> 1;
    }
    if ((k & 1) == 0)
    {
        cout << "Even\n";
    }
    else
    {
        cout << "Odd\n";
    }
}

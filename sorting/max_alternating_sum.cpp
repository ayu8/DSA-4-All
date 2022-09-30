void solve()
{
    long long int n;
    cin >> n;
    vector<ll> even;
    vector<ll> odd;
    long long int sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        a = abs(a);
        if (i % 2 == 1)
        {
            odd.push_back(a);
        }
        else
        {
            even.push_back(a);
        }
    }

    long long int e_sum = accumulate(even.begin(), even.end(), 0 LL);
    long long int o_sum = accumulate(odd.begin(), odd.end(), 0 LL);
    sum = o_sum - e_sum;
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    ll maxi = even[even.size() - 1];
    ll mini = odd[0];
    long long int sum2 = sum - (2 * (mini - maxi));
    cout << (max(sum, sum2)) << endl;
}
// Question Link:
// https://www.codechef.com/submit/PMA
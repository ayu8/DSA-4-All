//LordNeo
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vp;
typedef map<ll, ll> ml;
typedef unordered_map<ll, ll> uml;
#define pb push_back
#define ff first
#define ss second
const ll inf = INT_MAX;
const ll mod = 1000000007;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
int factorial(ll n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
ll sm(ll n)
{
    ll ans = n * (n + 1) / 2;
    return ans;
}
bool isprime(ll x)
{
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
bool perfectSquare(ld x)
{
    ld sr = sqrt(x);
    return ((sr - floor(sr)) == 0);
}
//function to join two sorted parts of array
void merge(ll *arr, ll p, ll q, ll r)
{
    ll n1 = q - p + 1;
    ll n2 = r - q;
    ll left[n1 + 1];
    ll right[n2 + 1];
    ll i, j;
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[i + p];
    }
    for (i = 0; i < n2; i++)
    {
        right[i] = arr[i + q + 1];
    }
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    i = 0, j = 0;
    for (ll k = p; k < r + 1; k++)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else if (left[i] > right[j])
        {
            arr[k] = right[j];
            j++;
        }
    }
}
// recursive function which calls the merge sort
void merge_sort(ll *arr, ll p, ll r)
{
    if (p < r)
    {
        ll q = ceil((p + r) / 2);
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
/*___________________*workplace*_______________________*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll test_case = 1;
    // cin >> test_case;
    while (test_case--)
    {
        ll n, i;
        cin >> n;
        ll arr[n];
        ll ans[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        merge_sort(arr, 0, n - 1);
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
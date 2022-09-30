int rob(vector<int> &nums)
{
    int n = nums.size();

    int t[n + 1];

    t[0] = 0;
    t[1] = nums[0];

    for (int i = 2; i <= n; i++)
    {
        t[i] = max(t[i - 2] + nums[i - 1], t[i - 1]);
    }

    return t[n];
}

// question link:
// https://leetcode.com/problems/house-robber/

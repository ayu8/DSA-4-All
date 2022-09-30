vector<int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    vector<int> res;

    list<int> l;

    int i = 0, j = 0;

    while (j < n)
    {

        if (!l.empty() && l.back() < arr[j])
        {
            while (!l.empty() && l.back() < arr[j])
            {
                l.pop_back();
            }
        }

        l.push_back(arr[j]);

        if (j - i + 1 < k)
            j++;

        else
        {
            res.push_back(l.front());
            if (arr[i] == l.front())
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }

    return res;
}
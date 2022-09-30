static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<pair<int, int>> v;
        
        for (int i=0; i<n; i++) {
            pair<int, int> p;
            p.first = arr[i];
            int count=0, x=arr[i];
            
            while(x) {
                x = x&(x-1);
                count++;
            }
            p.second = count;
            
            v.push_back(p);
        }
        
        stable_sort(v.begin(), v.end(), cmp);
        
        for (int i=0; i<n; i++) {
            arr[i] = v[i].first;
        }
        
    }

// question link:
// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1

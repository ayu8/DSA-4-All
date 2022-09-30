class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        vector<int> lengthOfTrip = vector<int>(1001);
        for (auto trip : trips){
            lengthOfTrip[trip[1]] += trip[0];
            lengthOfTrip[trip[2]] -= trip[0];
        }
        int carLoad = 0;
        for (int i = 0; i < 1001 && carLoad <= capacity; i++)
        {
            carLoad += lengthOfTrip[i];
            if(carLoad > capacity) return false;
        }

        return true;
    }
};

// Question Link:
// https://leetcode.com/problems/car-pooling/
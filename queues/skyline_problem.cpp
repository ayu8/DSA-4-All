struct Item
{
    Item(int l, int r, int h) 
    {
        m_left = l;
        m_right = r;
        m_height = h;
    }
    
    Item(const vector<int> &building) 
    {
        m_left = building[0];
        m_right = building[1];
        m_height = building[2];
    }
    
    bool operator<(const Item &rhs) const
    {
        return m_height < rhs.m_height;
    }
    
    int m_left, m_right, m_height;
};

// The worker function
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
{
    vector<pair<int, int> > res;
    if (buildings.size() == 0) {
        return res;
    }
    
    priority_queue<Item> queue;
    int x = buildings[0][0];    // X-coordinate of next check point
    int y = 0;                  // current height
    int p = 0;                  // Next building
    while (true) {
        // Two kind of check point: a processed building's right edge or 
        // a new building's left edge
        if (p == buildings.size() || x < buildings[p][0]) {
            // meet a processed building's right edge
            while (!queue.empty() && x >= queue.top().m_right) {
                queue.pop();
            }
            
            if (queue.empty()) {
                // On the ground
                y = 0;
                res.push_back(pair<int, int>(x, y));
                
                // Next x
                if (p == buildings.size()) {
                    break;      // No more building
                } else {
                    x = buildings[p][0];
                }
            } else {
                if (queue.top().m_height < y) {
                    y = queue.top().m_height;
                    res.push_back(pair<int, int>(x, y));
                }
                
                // Next x
                if (p == buildings.size()) {
                    x = queue.top().m_right;
                } else {
                    x = min(queue.top().m_right, buildings[p][0]);
                }
            }
        } else {
            // Meet a new building's left edge
            while (p != buildings.size() && buildings[p][0] == x) {
                queue.push(Item(buildings[p++]));
            }
            
            if (queue.top().m_height > y) {
                y = queue.top().m_height;
                res.push_back(pair<int, int>(x, y));
            }
            
            // Determine new x
            if (p == buildings.size()) {
                x = queue.top().m_right;
            } else {
                x = min(queue.top().m_right, buildings[p][0]);
            }
        }
    }
        
    return res;
}

// question link:
// https://leetcode.com/problems/the-skyline-problem/

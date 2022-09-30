//implementing the tushar roys explanation
class Solution {
    private:
    struct sky {
        int x, height;
        bool isStart;
        sky(int x, int height, bool isStart) : x(x), height(height), isStart(isStart) {}
    };
    struct comp {
        bool operator()(const sky& s1, const sky& s2) {
            if(s1.x != s2.x) return s1.x < s2.x;
            if(s1.isStart && s2.isStart) return s1.height > s2.height;
            if(s1.isStart) return true;
            if(s2.isStart) return false;
            return s1.height < s2.height;
        }
    };
       
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<sky> skyline;
        for(vector<int> b: buildings) {
            skyline.push_back(sky(b[0], b[2], true));
            skyline.push_back(sky(b[1], b[2], false));
        }
        
        sort(skyline.begin(), skyline.end(), comp());
        map<int, int, greater<int>> pq;
        vector<vector<int>> result;
        int prevMax=0;
        
        pq[0]=1;
        
        for(int i=0; i<skyline.size(); i++) {
            if(skyline[i].isStart) {
                pq[skyline[i].height]++;
            } else {
                pq[skyline[i].height]--;
                if(pq[skyline[i].height] == 0)
                    pq.erase(skyline[i].height);
            }
            
            auto newH = pq.begin();
            
            if(newH->first != prevMax) {
                result.push_back({skyline[i].x, newH->first});
                prevMax=newH->first;
            }
        }
        
        return result;
    }
        };
    
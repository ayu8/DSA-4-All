### DFS Approach


class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>&image, int color, int delrow[], int delcol[], int intitalColour){
        ans[row][col] = color;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if( nrow >= 0 && nrow < n && ncol >= 0 && 
               ncol < m && ans[nrow][ncol] != color && 
               image[nrow][ncol] == intitalColour
              ) {
                dfs(nrow, ncol, ans, image, color, delrow, delcol, intitalColour);
            } 
        }
        
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColour = image[sr][sc];
        vector<vector<int>> ans = image;
        int del_row[] = {-1, 0, +1, 0};
        int del_col[] = {0, +1, 0, -1};
        dfs(sr,sc,ans, image,color, del_row, del_col, initialColour);
        return ans;
        
    }
};


### BFS Approach


class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>&image, int color, int delrow[], int delcol[], int intitalColour){
        ans[row][col] = color;
        
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>>q;
        q.push({row, col});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if( nrow >= 0 && nrow < n && ncol >= 0 && 
                   ncol < m && ans[nrow][ncol] != color && 
                   image[nrow][ncol] == intitalColour
                  ) {
                    ans[nrow][ncol] = color;
                    q.push({nrow, ncol});
                } 
            }   
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColour = image[sr][sc];
        vector<vector<int>> ans = image;
        int del_row[] = {-1, 0, +1, 0};
        int del_col[] = {0, +1, 0, -1};
        bfs(sr,sc,ans, image,color, del_row, del_col, initialColour);
        return ans;
        
    }
};

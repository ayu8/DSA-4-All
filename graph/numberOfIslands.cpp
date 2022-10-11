### BFS Approach (4 direction)


class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid, int del_row[], int del_col[]){
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row, col});
        int n = grid.size(), m = grid[0].size();
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = r + del_row[i];
                int ncol = c + del_col[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && 
                !vis[nrow][ncol] ) {

                    vis[nrow][ncol] = 1;      
                    q.push({nrow, ncol});
                }
            }
        }  
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    islands++;
                    bfs(i,j,vis,grid,delta_row,delta_col);
                }
            }
        }
        return islands;
    }
    
};


### DFS Approach


class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0' || vis[row][col]){
            return;
        }
        vis[row][col] = 1;
        dfs(row + 1, col, vis, grid);
        dfs(row, col + 1, vis, grid);
        dfs(row - 1, col, vis, grid);
        dfs(row, col - 1, vis, grid);
    }  
    
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    islands++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return islands;
    }
    
};

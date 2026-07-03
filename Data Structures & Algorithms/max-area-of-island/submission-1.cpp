class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<vector<int>>visited;
    int n,m;

    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || visited[i][j]){
            return 0;
        }

        visited[i][j] = true; 
        int ans  = 1;
        for(int dir=0; dir<4; dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            ans += dfs(ni,nj,grid);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n  = grid.size();
        m = grid[0].size();
        visited.assign(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j]==1){
                    if(!visited[i][j]){
                        ans = max(ans,dfs(i,j,grid));
                    }
                }
            }
        }

        return ans;
    }
};

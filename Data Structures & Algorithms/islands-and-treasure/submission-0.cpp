class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    const int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int lvl = 1;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto coordinate = q.front();
                q.pop();
                int x = coordinate.first;
                int y = coordinate.second;
                
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==INF){
                        grid[nx][ny] = lvl;
                        q.push({nx,ny});
                    }
                }
            }
            lvl++;
        }
    }
};

class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                } else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int time = 0;
        while(!q.empty()){
            int size = q.size();
            bool isProccessed = false;
            while(size--){
                auto coordinate = q.front();
                q.pop();
                int x = coordinate.first;
                int y = coordinate.second;
                
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        isProccessed = true;
                        fresh--;
                    }
                }
            }
           
            if(isProccessed)
            time++;
        }

        if(fresh) return -1;
        return time;
    }
};

class Solution {
   public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> p(n, vector<int>(m, 0));
        vector<vector<int>> a(n, vector<int>(m, 0));
        queue<pair<char, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            q.push({'p', {i, 0}});
            q.push({'a', {i, m - 1}});
            p[i][0] = 1;
            a[i][m - 1] = 1;
        }
        for (int i = 0; i < m; i++) {
            q.push({'p', {0, i}});
            q.push({'a', {n - 1, i}});
            p[0][i] = 1;
            a[n - 1][i] = 1;
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            char type = front.first;
            int x = front.second.first;
            int y = front.second.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && h[x][y] <= h[nx][ny]) {
                    if (type == 'p' && !p[nx][ny]) {
                        p[nx][ny] = 1;
                        q.push({'p', {nx, ny}});
                    }

                    if (type == 'a' && !a[nx][ny]) {
                        a[nx][ny] = 1;
                        q.push({'a', {nx, ny}});
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] && a[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};

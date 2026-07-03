class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    void bfs(queue<pair<int,int>>& q,
             vector<vector<int>>& vis,
             vector<vector<int>>& h) {

        int n = h.size();
        int m = h[0].size();

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < m &&
                    !vis[nx][ny] &&
                    h[nx][ny] >= h[x][y]) {

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<vector<int>> p(n, vector<int>(m, 0));
        vector<vector<int>> a(n, vector<int>(m, 0));

        queue<pair<int,int>> qp, qa;

        // Left & Right boundaries
        for (int i = 0; i < n; i++) {
            qp.push({i, 0});
            qa.push({i, m - 1});
            p[i][0] = 1;
            a[i][m - 1] = 1;
        }

        // Top & Bottom boundaries
        for (int j = 0; j < m; j++) {
            if (!p[0][j]) {
                qp.push({0, j});
                p[0][j] = 1;
            }

            if (!a[n - 1][j]) {
                qa.push({n - 1, j});
                a[n - 1][j] = 1;
            }
        }

        bfs(qp, p, h);
        bfs(qa, a, h);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] && a[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};
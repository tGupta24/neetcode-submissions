class Solution {
public:
    vector<int>visited;
    bool dfs(int u,int parent,vector<vector<int>>adj){
        // base case

        visited[u] = 1;

        for(auto v:adj[u]){
            if(v==parent){
                continue;
            } 

            if(visited[v]){
                return true;
            }

            if(dfs(v,u,adj)==1){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        visited.assign(n, 0);
        if(dfs(0,-1,adj)){
            return false;
        }

        for(auto i:visited){
            if(i==0) return false;
        }
        

        return true;
        
    }
};

class Solution {
public:
    
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>graph(26)    ;
        int n = words.size();
       
        for(int i=0; i<n-1; i++){
            // for(int j=i+1; j<n; j++){
                string a = words[i];
                string b = words[i+1];
                 for(int k=0; k<min(a.size(),b.size()); k++){
                    if(a[k]!=b[k]){
                       graph[a[k]-'a'].push_back(b[k]-'a');
                       break;
                    }
                 }
                 if(a.size()>b.size() && b == a.substr(0,b.size())){
                    return "";
                 }
            // }
        }
        set<int>totalNodes;
        for(auto i:words){
            for(auto j:i){
                totalNodes.insert(j-'a');
            }
        }
        vector<int>indeg(26);
        for(auto i:graph){
            for(auto j:i){
                indeg[j]++;
            }
        }
        queue<int>q;
        vector<int>topoSort;
        for(int i=0; i<26; i++){
            if(indeg[i]==0 && totalNodes.count(i)){
                q.push(i);
                topoSort.push_back(i);

            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i:graph[front]){
                indeg[i]--;
                if(indeg[i]==0){
                    topoSort.push_back(i);
                    q.push(i);
                }
            }
        }
        
        if(topoSort.size()!=totalNodes.size()){
            return "";
        } 
       
        string ans = "";
        for (auto node : topoSort) {
            ans += char(node + 'a');
        }
        return ans;
    
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            queue<int>q;
            q.push(i);
            visited[i] = 1;
            int nodes = 0;
            int e_Count = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                nodes++;
                e_Count += adj[node].size();
                for(auto it:adj[node]){
                    if(!visited[it]){
                        visited[it] = 1;
                        q.push(it);
                    }
                }
            }
            e_Count = e_Count / 2;
            if(e_Count == nodes * (nodes-1) / 2){
                cnt++;
            }
        }
        return cnt;
    }
};
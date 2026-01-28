class Solution {
public:
    typedef pair<int,int>P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        vector<bool>visited(n,false);
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,0});
        int min_dist = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int node = it.second;
            if(visited[node]){
                continue;
            }
            visited[node] = true;
            min_dist += dist;
            for(auto it:adj[node]){
                int node2 = it.first;
                int dist2 = it.second;
                if(!visited[node2]){
                    pq.push({dist2,node2});
                }
            }
        }
        return min_dist;
    }
};
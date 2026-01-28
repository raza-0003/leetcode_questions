class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i == parent[i]){
            return i;
        }
        return find(parent[i],parent);
    }
    void Union(int x, int y,vector<int>&parent){
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);
        if(x_parent != y_parent){
            // kisi ek ko papa bana do --> let say y ko bana diya
            parent[x_parent] = y_parent;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        vector<pair<int, pair<int,int>>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                int d = abs(x1-x2) + abs(y1-y2);
                edges.push_back({d,{i,j}});
                edges.push_back({d,{j,i}});
            }
        }
        int min_sum = 0;
        sort(edges.begin(),edges.end());
        for(auto it:edges){
            int d = it.first;
            int u = it.second.first;
            int v = it.second.second;
            int u_parent = find(u,parent);
            int v_parent = find(v,parent);
            if(u_parent != v_parent){
                Union(u,v,parent);
                min_sum += d;
            }
        }
        return min_sum;
    }
};
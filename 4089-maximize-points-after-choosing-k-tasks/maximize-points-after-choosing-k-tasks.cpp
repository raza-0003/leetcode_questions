class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        long long sum = 0;
        int n = technique1.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({technique1[i]-technique2[i],i});
        }
        vector<int>visited(n,0);
        while(k){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int ind = it.second;
            visited[ind] = 1;
            sum += technique1[ind];
            k--;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                sum += max(technique1[i],technique2[i]);
            }
        }
        return sum;

    }
};
class Solution {
public:
    int maxDistance(string str, int k) {
        int ans = -1e9;
        int n = 0;
        int w = 0;
        int s = 0;
        int e = 0;
        
        for(char c : str){
            if(c=='N'){
                n++;
            }else if(c=='W'){
                w++;
            }else if(c=='S'){
                s++;
            }else{
                e++;
            }
            int maxNs = max(n, s);
            int minNs = min(n, s);
            int maxWe = max(w, e);
            int minWe = min(w, e);
            int p = min(minNs+minWe, k);
            ans =max(ans,(maxNs + maxWe -minNs -minWe + 2*p));
            
        }
        return ans;
        
    }
};
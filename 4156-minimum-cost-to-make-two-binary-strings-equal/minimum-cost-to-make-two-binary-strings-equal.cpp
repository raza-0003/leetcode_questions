class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) { 
        int n = s.size();
        long long ans = 0;
        int type1 = 0;
        int type2 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1' && t[i] == '0'){
                type1++;
            }
            else if(s[i] == '0' && t[i] == '1'){
                type2++;
            }
        }
        int mini = min(type1,type2);
        int maxi = max(type1,type2);
        ans += min(2LL * mini * flipCost,1LL*mini*swapCost);
        maxi -= mini;
        ans += min((crossCost + swapCost)*1LL*(maxi/2),(maxi/2) * 2LL * flipCost);
        if(maxi % 2){
            ans += flipCost;
        }
        return ans;

    }
};
class Solution {
public:
    int helper(string &s,char ch1,char ch2){
        int n = s.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int maxL = 0;
        unordered_map<int,int>diffMap;
        for(int i=0;i<n;i++){
            if(s[i] != ch1 && s[i] != ch2){
                cnt1 = 0;
                cnt2 = 0;
                diffMap.clear();
                continue;
            }
            if(s[i] == ch1){
                cnt1++;
            }
            if(s[i] == ch2){
                cnt2++;
            }
            if(cnt1 == cnt2){
                maxL = max(maxL,cnt1+cnt2);
            }
            int diff = cnt1-cnt2;
            if(diffMap.count(diff)){
                maxL = max(maxL,i-diffMap[diff]);
            }else{
                diffMap[diff] = i;
            }
        }
        return maxL;
    }
    int longestBalanced(string s) {
        int n = s.size();
        //case-1
        int cnt = 1;
        int maxL = 0;
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                cnt++;
            }
            else{
                maxL = max(maxL,cnt);
                cnt = 1;
            }
        }
        maxL = max(maxL,cnt);
        // case-2 --> (a,b),(a,c),(b,c)
        maxL = max(maxL,helper(s,'a','b'));
        maxL = max(maxL,helper(s,'a','c'));
        maxL = max(maxL,helper(s,'b','c'));

        // case-3 -->(when all are included)
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;
        unordered_map<string,int>diffMap;
        for(int i=0;i<n;i++){
            if(s[i] == 'a'){
                cntA++;
            }
            if(s[i] == 'b'){
                cntB++;
            }
            if(s[i] == 'c'){
                cntC++;
            }
            if(cntA == cntB && cntA == cntC){
                maxL = max(maxL,cntA+cntB+cntC);
            }
            int diffAB = cntA-cntB;
            int diffAC = cntA-cntC;
            string key = to_string(diffAB) + "%" + to_string(diffAC);
            if(diffMap.count(key)){
                maxL = max(maxL,i-diffMap[key]);
            }else{
                diffMap[key] = i;
            }
        }
        return maxL;
    }
};
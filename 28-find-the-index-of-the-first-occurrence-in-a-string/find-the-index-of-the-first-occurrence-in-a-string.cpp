class Solution {
public:
    int strStr(string haystack, string needle) {
        int firstInd = -1;
        if(haystack == needle) return 0;
        int nlen = needle.size();
        int hlen = haystack.size();
        if(nlen > hlen) return -1;
        for(int i=0;i<hlen;i++){
            if(needle == haystack.substr(i,nlen)){
                return i;
            }
        }
        return firstInd;
        
    }
};
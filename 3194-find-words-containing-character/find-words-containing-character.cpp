class Solution {
public:
    bool checkElem(string &str,char tar){
        int n = str.size();
        for(int i=0;i<n;i++){
           if( str[i] == tar){
                return true;
                break;
           }     
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(checkElem(words[i],x)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
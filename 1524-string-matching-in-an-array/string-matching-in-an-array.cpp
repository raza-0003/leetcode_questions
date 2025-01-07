class Solution {
public:
    bool compareByLen(const string &a,const string &b){
        return a.size() > b.size();
    }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        unordered_set<string>st;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() > b.size();
        });
        for(int i=0;i<n;i++){
            string m_str = words[i];
            for(int j=i+1;j<n;j++){
                string s_str = words[j];
                size_t position = m_str.find(s_str);
                if(position != string::npos){
                    st.insert(words[j]);
                }
            }
        }
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};
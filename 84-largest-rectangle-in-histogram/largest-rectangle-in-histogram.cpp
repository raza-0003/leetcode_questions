class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int>st;
        int maxA = 0;
        int n = nums.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.top()] > nums[i])){
                int height = nums[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top() -1;
                }
                maxA = max(maxA,width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};

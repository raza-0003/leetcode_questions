class Solution {
public:
    bool isPalindrome(int n){
        if(n == 1 || n == 0) return true;
        int temp = n;
        int x = 0;
        while(temp){
            int d = temp & 1;
            x = (x << 1)  | d;
            temp = temp / 2;
        }
        return x == n;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int>ans(5002,0);
        for(int i=0;i<=5001;i++){
            if(isPalindrome(i)){
                ans[i] = 1;
            }
        }
        vector<int>nearOne(5002);
        int lasti = -1;
        for(int i=0;i<=5001;i++){
            if(ans[i] == 1){
                nearOne[i] = i;
                lasti = i;
            }
            else if(ans[i] == 0){
                nearOne[i] = lasti;
            }
        }
        int last2i = -1;
        for(int i=5001;i>=0;i--){
            if(ans[i] == 1){
                last2i = i;
            }
            else if(last2i != -1){
                if(nearOne[i] == -1){
                    nearOne[i] = last2i;
                }
                else if(last2i - i < i - nearOne[i]){
                    nearOne[i] = last2i;
                }
                
            }
        }
        vector<int>fans;
        for(int i=0;i<nums.size();i++){
            if(ans[nums[i]] == 1){
                fans.push_back(0);
            }
            else if(ans[nums[i]] == 0){
                fans.push_back(abs(nums[i] - nearOne[nums[i]]));
            }
        }
        return fans;

    }
};
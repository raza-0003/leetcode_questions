class Solution {
public:
    int help(int n){
        int ans = 0;
        while(n){
            int temp = n %  10;
            ans += (temp * temp);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = help(slow);  // flloyad warshal algorithm slow move one step
            fast = help(help(fast)); // flloyad washal algorithm fast moves 2 steps

        }while(slow != fast);
        return slow == 1;
    }
};
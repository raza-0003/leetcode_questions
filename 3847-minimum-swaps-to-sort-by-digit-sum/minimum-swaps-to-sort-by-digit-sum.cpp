class Solution {
public:
    int digitSum(int number) {
        int sum = 0;
        while (number > 0) {
            int digit = number % 10;
            sum += digit;
            number /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // step 1: create a sorted version with custom criteria (digitsum,value)
        vector<pair<int,int>> sortedArr;
        for(auto it:nums){
            sortedArr.push_back({digitSum(it),it});
        }
        // sort the array based on the digtit sum,then value
        sort(sortedArr.begin(),sortedArr.end());
        // step 2: Map values to original index
        unordered_map<int,int>valueToIndex;
        for(int i=0;i<n;i++){
            valueToIndex[nums[i]] = i;
        }
        // step3 : mark visited element and perform cycle detection
        vector<bool>visited(n,false);
        int swap = 0;
        for(int i=0;i<n;i++){
            int correctVal = sortedArr[i].second;
            // skip if it is already visited or in the right place
            if(visited[i] || nums[i] == correctVal){
                continue;
            }
            int cycle_size = 0;
            int j = i;
            // traversal of the cycle
            while(!visited[j]){
                visited[j] = true;
                int nextVal = sortedArr[j].second;
                j = valueToIndex[nextVal];
                cycle_size++;            
            }
            if(cycle_size > 1 ){
                swap += (cycle_size -1);
            }
        }
        return swap;
    }
};
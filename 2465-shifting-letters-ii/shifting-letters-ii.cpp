class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<long long> diff(n + 1, 0);  // Use long long to handle large numbers
        
        // Process all shifts using difference array
        for(const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 1 ? 1 : -1;
            
            diff[start] += direction;
            diff[end + 1] -= direction;
        }
        
        // Calculate prefix sum and apply shifts
        long long currentShift = 0;
        for(int i = 0; i < n; i++) {
            currentShift += diff[i];
            // Handle negative shifts
            long long totalShifts = ((currentShift % 26) + 26) % 26;
            int newChar = (s[i] - 'a' + totalShifts) % 26;
            s[i] = 'a' + newChar;
        }
        
        return s;
    }
};
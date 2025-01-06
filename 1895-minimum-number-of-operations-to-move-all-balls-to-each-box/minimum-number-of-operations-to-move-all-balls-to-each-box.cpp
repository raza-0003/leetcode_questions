class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
    std::vector<int> answer(n, 0);
    
    // Left to right pass
    int balls = 0; // Number of balls encountered so far
    int operations = 0; // Cumulative operations
    for (int i = 0; i < n; ++i) {
        answer[i] += operations;
        balls += (boxes[i] == '1'); // Add current ball to the count
        operations += balls; // Add operations to move balls to this position
    }

    // Right to left pass
    balls = 0;
    operations = 0;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] += operations;
        balls += (boxes[i] == '1'); // Add current ball to the count
        operations += balls; // Add operations to move balls to this position
    }

    return answer;

    }
};
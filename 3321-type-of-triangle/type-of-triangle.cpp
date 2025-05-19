class Solution {
public:
    string triangleType(vector<int>& nums) {
        // check is it a triangle or not
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        if(a + b > c && b + c > a && c + a > b ){
            // it means it is a triangle
            if(a == b && b == c){
                return "equilateral";
            }
            else if(a==b || b == c || a== c){
                return "isosceles";
            }
            return "scalene";
        }
        // it means not a triangle 
        return "none";
    }
};
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = 30 * hour + double(minutes) * 0.5;
        double mints = 6 * double(minutes);
        double ans = abs(hr-mints);
        return min(ans,360-ans);
    }
};
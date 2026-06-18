class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = 0;
        angle += minutes * 6;
        double hour_ang = 0;
        hour_ang += hour * 30;
        double hr = double(minutes) * double(0.5);
        double ans = abs(angle-hour_ang-hr);
        return min(ans,360-ans);
    }
};
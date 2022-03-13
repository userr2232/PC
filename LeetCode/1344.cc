class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = static_cast<double>(hour % 12) * 30;
        hour_angle += 30 * static_cast<double>(minutes) / 60;
        double minute_angle = 360 * static_cast<double>(minutes) / 60;
        double alpha = abs(hour_angle - minute_angle);
        double beta = 360 - alpha;
        return min(alpha, beta);
    }
};
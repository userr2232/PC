class Solution {
public:
    bool isRobotBounded(string instructions) {
        complex<double> pos{0, 0};
        complex<double> dir{1, 0};
        for(char c : instructions) {
            if(c == 'G') pos += dir;
            else if(c == 'L') dir = {dir.imag(), -dir.real()};
            else dir = {-dir.imag(), dir.real()};
        }
        return pos == complex<double>{0, 0} || dir.real() != 1;
    }
};
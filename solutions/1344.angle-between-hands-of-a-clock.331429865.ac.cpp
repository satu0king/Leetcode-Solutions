class Solution {
public:
  double angleClock(int hour, int minutes) {
    double hourAngle = (hour + minutes / 60.0) * 360 / 12;
    double minuteAngle = minutes * 6;

    double d = abs(hourAngle - minuteAngle);
    return min(d, 360 - d);
  }
};

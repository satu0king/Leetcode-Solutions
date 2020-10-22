class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> flights(n + 1);

    for (auto &booking : bookings) {
      flights[booking[0] - 1] += booking[2];
      flights[booking[1]] -= booking[2];
    }

    for (int i = 1; i < n; i++)
      flights[i] += flights[i - 1];

    flights.pop_back();
    return flights;
  }
};

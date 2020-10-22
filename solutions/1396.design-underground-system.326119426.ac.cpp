class UndergroundSystem {

  unordered_map<int, pair<string, int>> checkInMap;
  map<pair<string, string>, pair<int, int>> stationData;

public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    checkInMap[id] = make_pair(stationName, t);
  }

  void checkOut(int id, string stationName, int t) {
    auto [startStation, inTime] = checkInMap[id];
    auto p = make_pair(startStation, stationName);
    auto &data = stationData[p];
    data.first += t - inTime;
    data.second++;
    checkInMap.erase(id);
  }

  double getAverageTime(string startStation, string endStation) {
    auto &data = stationData[make_pair(startStation, endStation)];
    return data.first / (0.0 + data.second);
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

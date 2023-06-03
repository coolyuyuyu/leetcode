class UndergroundSystem {
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        m_inRecords[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        const auto& [startStation, inTime] = m_inRecords[id];
        auto& [travelTime, travelCnt] = m_statistics[startStation + "->" + stationName];
        travelTime += (t - inTime);
        travelCnt += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        const auto& [travelTime, travelCnt] = m_statistics[startStation + "->" + endStation];
        return static_cast<double>(travelTime) / travelCnt;
    }

private:
    unordered_map<int, pair<string, int>> m_inRecords;
    unordered_map<string, pair<int, int>> m_statistics;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

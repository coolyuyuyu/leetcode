class UndergroundSystem {
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        m_startRecords[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        const auto& [startStation, startTime] = m_startRecords[id];
        auto& [sum, cnt] = m_statistics[startStation + ">" + stationName];
        sum += t - startTime;
        cnt += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        const auto& [sum, cnt] = m_statistics[startStation + ">" + endStation];
        return sum * 1.0 / cnt;
    }

private:
    unordered_map<int, pair<string, int>> m_startRecords; // id -> <in station, in time>
    unordered_map<string, pair<int, int>> m_statistics; // in to out station -> <sum, cnt>
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

class Logger {
public:
    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        auto p = m_msg2time.emplace(message, timestamp);
        if (p.second) {
            return true;
        }
        else {
            if (timestamp - p.first->second >= 10) {
                p.first->second = timestamp;
                return true;
            }
            else {
                return false;
            }
        }
    }

private:
    unordered_map<string, int> m_msg2time;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

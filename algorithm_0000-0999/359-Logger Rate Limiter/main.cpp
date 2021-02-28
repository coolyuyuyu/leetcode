class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto p = m_timestamps.emplace(message, timestamp);
        if (p.second) {
            return true;
        }
        else {
            int lastTimestamp = p.first->second;
            if (timestamp >= (lastTimestamp + 10)) {
                p.first->second = timestamp;
                return true;
            }
            else {
                return false;
            }
        }
    }

private:
    unordered_map<string, int> m_timestamps;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
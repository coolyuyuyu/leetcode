class Solution {
public:
    int computeMinNumDigit(int n, int limit) {
        for (int numDigit = 1; numDigit < 6; ++numDigit) {
            int capacity = 0;
            for (int i = 1, cnt = 9; i <= numDigit; ++i, cnt *= 10) {
                if ((i + numDigit + 3) < limit) {
                    capacity += (limit - i - numDigit - 3) * cnt;
                }
            }
            if (n <= capacity) {
                return numDigit;
            }
        }

        return 0;
    }

    vector<string> constructPrefixMsgs(const string& message, int limit, int numTotalDigit) {
        vector<string> msgs;
        size_t msgIdx = 0;
        for (int numDigit = 1; true; ++numDigit) {
            for (int i = pow(10, numDigit - 1), end = pow(10, numDigit), capacity = limit - numDigit - numTotalDigit - 3; i < end; ++i) {
                string msg = message.substr(msgIdx, capacity);
                msg += "<";
                msg += std::to_string(i);
                msg += "/";
                msgs.push_back(msg);

                msgIdx += capacity;
                if (message.size() <= msgIdx) {
                    return msgs;
                }
            }
        }

        return msgs;
    }

    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        int numTotalDigit = computeMinNumDigit(n, limit);
        if (numTotalDigit <= 0) {
            return {};
        }

        vector<string> msgs = constructPrefixMsgs(message, limit, numTotalDigit);
        for (string& msg : msgs) {
            msg += std::to_string(msgs.size());
            msg += ">";
        }

        return msgs;
    }
};

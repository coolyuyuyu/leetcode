class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn == 0) {
            return {"0:00"};
        }

        std::function<string(int)> f = [](int mask) {
            int hr = mask >> 6;
            if (hr > 11) { return string(""); }
            int min = mask & 0b111111;
            if (min > 59) { return string(""); }

            string hrStr = std::to_string(hr);
            string minStr = std::to_string(min);
            if (minStr.size() == 1) { minStr = "0" + minStr; }

            return hrStr + ":" + minStr;
        };

        vector<string> ret;

        // Gosper's hack: Iterate all the m-bit state where there are k 1-bits.
        int m = 10, k = turnedOn;
        int state = (1 << k) - 1;
        while (state < (1 << m)) {
            // DoSomething(state);
            string t = f(state);
            if (!t.empty()) {
                ret.push_back(t);
            }

            int c = state & -state;
            int r = state + c;
            state = (((r ^ state) >> 2) / c) | r;
        }

        return ret;
    }
};

class Solution {
public:
    // Time: O(n), Space: O(n)
    vector<int> f1(const vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);

        stack<int> stk; // <index>
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                ret[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.emplace(i);
        }

        return ret;
    }

    // Time: O(n), Space: O(1);
    vector<int> f2(const vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);

        stack<int> stk; // <index>
        for (int hottest = temperatures.back(), i = temperatures.size(); 0 < i--;) {
            if (hottest <= temperatures[i]) {
                hottest = temperatures[i];
                continue;
            }

            int ans = 1;
            while (temperatures[i + ans] <= temperatures[i]) {
                ans += ret[i + ans];
            }
            ret[i] = ans;
        }

        return ret;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //return f1(temperatures);
        return f2(temperatures);
    }
};

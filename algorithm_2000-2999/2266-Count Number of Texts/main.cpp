class Solution {
private:
    static vector<int> m_cnts3;
    static vector<int> m_cnts4;
    static const int kModVal;
public:
    int count3(size_t numDigits) {
        if (numDigits < m_cnts3.size()) {
            return m_cnts3[numDigits];
        }

        for (size_t i = m_cnts3.size(); i <= numDigits; ++i) {
            m_cnts3.push_back(((m_cnts3[i - 3] + m_cnts3[i - 2]) % kModVal + m_cnts3[i - 1]) % kModVal);
        }
        return m_cnts3[numDigits];
    }

    int count4(size_t numDigits) {
        if (numDigits < m_cnts4.size()) {
            return m_cnts4[numDigits];
        }

        for (size_t i = m_cnts4.size(); i <= numDigits; ++i) {
            m_cnts4.push_back((((m_cnts4[i - 4] + m_cnts4[i - 3]) % kModVal + m_cnts4[i - 2]) % kModVal + m_cnts4[i - 1]) % kModVal);
        }
        return m_cnts4[numDigits];
    }

    int btmDp1(const string& pressedKeys) {
        int cnt = 1;
        for (size_t numDigits = 0, i = 0; i <= pressedKeys.size(); ++i) {
            if ((0 < i && pressedKeys[i] != pressedKeys[i - 1]) || i == pressedKeys.size()) {
                if (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') {
                    cnt = ((long)cnt * count4(numDigits)) % kModVal;
                }
                else {
                    cnt = ((long)cnt * count3(numDigits)) % kModVal;
                }
                cnt %= kModVal;

                numDigits = 1;
            }
            else {
                ++numDigits;
            }
        }

        return cnt;
    }

    int btmDp2(const string& keys) {
        vector<int> dp(keys.size() + 1);
        dp[0] = 1;
        for (size_t i = 0; i < keys.size(); ++i) {
            dp[i + 1] = dp[i];
            if (0 < i && keys[i] == keys[i - 1]) {
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % kModVal;
                if (1 < i && keys[i] == keys[i - 2]) {
                    dp[i + 1] = (dp[i + 1] + dp[i - 2]) % kModVal;
                    if (2 < i && keys[i] == keys[i - 3] && (keys[i] == '7' || keys[i] == '9')) {
                        dp[i + 1] = (dp[i + 1] + dp[i - 3]) % kModVal;
                    }
                }
            }
        }

        return dp[keys.size()];
    }

    int countTexts(string pressedKeys) {
        //return btmDp1(pressedKeys);
        return btmDp2(pressedKeys);
    }
};

vector<int> Solution::m_cnts3 = {1,1,2};
vector<int> Solution::m_cnts4 = {1,1,2,4};
const int Solution::kModVal = 1000000007;

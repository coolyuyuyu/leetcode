class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        std::function<vector<string>(const string&)> parse = [](const string& s) {

            vector<string> ret;
            for (int i = 0, n = s.size(); i < n; ++i) {
                if (isdigit(s[i])) {
                    int j = i + 1;
                    while (j < n && isdigit(s[j])) {
                        ++j;
                    }
                    ret.push_back(s.substr(i, j - i));
                    i = j - 1;
                }
                else {
                    ret.push_back(s.substr(i, 1));
                }
            }

            return ret;
        };

        std::function<unordered_set<int>(const string&)> computeCnts = [](const string& s) -> unordered_set<int> {
            int d = std::stoi(s);
            if (s.size() == 1) {
                return {d};
            }
            else if (s.size() == 2) {
                int a = d / 10;
                int b = d % 10;
                return {d, a + b};
            }
            else {
                assert(s.size() == 3);
                int a = d / 100;
                int b = (d / 10) % 10;
                int c = d % 10;
                return {d, a * 10 + b + c, a + b * 10 + c, a + b + c};
            }
        };

        vector<string> arr1 = parse(s1), arr2 = parse(s2);
        int size1 = arr1.size(), size2 = arr2.size();
        unordered_set<long long> visited;
        std::function<bool(int, int, int, int)> dfs = [&](int idx1, int cnt1, int idx2, int cnt2) {
            long long hash = 1e8 * idx1 + 1e5 * cnt1 + 1e3 * idx2 + cnt2;
            if (visited.find(hash) != visited.end()) {
                return false;
            }
            if (idx1 >= size1 && idx2 >= size2) {
                return cnt1 == cnt2;
            }
            if (idx1 >= size1 && cnt1 == 0) {
                visited.insert(hash);
                return false;
            }
            if (idx2 >= size2 && cnt2 == 0) {
                visited.insert(hash);
                return false;
            }

            if (idx1 < size1 && isdigit(arr1[idx1][0])) {
                for (int cnt : computeCnts(arr1[idx1])) {
                    if (dfs(idx1 + 1, cnt1 + cnt, idx2, cnt2)) {
                        return true;
                    }
                }
                visited.insert(hash);
                return false;
            }
            if (idx2 < size2 && isdigit(arr2[idx2][0])) {
                for (int cnt : computeCnts(arr2[idx2])) {
                    if (dfs(idx1, cnt1, idx2 + 1, cnt2 + cnt)) {
                        return true;
                    }
                }
                visited.insert(hash);
                return false;
            }

            if (cnt1 != 0 && cnt2 != 0) {
                int cnt = std::min(cnt1, cnt2);
                return dfs(idx1, cnt1 - cnt, idx2, cnt2 - cnt);
            }
            else if (cnt1 != 0 && cnt2 == 0) {
                return dfs(idx1, cnt1 - 1, idx2 + 1, 0);
            }
            else if (cnt1 == 0 && cnt2 != 0) {
                return dfs(idx1 + 1, 0, idx2, cnt2 - 1);
            }
            else {
                if (arr1[idx1] == arr2[idx2]) {
                    return dfs(idx1 + 1, 0, idx2 + 1, 0);
                }
                else {
                    visited.insert(hash);
                    return false;
                }
            }
        };
        return dfs(0, 0, 0, 0);
    }
};

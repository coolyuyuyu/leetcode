class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();

        unordered_map<string, map<int, string>> user2websites;
        for (int i = 0; i < n; ++i) {
            user2websites[username[i]][timestamp[i]] = website[i];
        }

        map<tuple<string, string, string>, int> pattern2cnt;
        for (const auto& [_, websites] : user2websites) {
            set<tuple<string, string, string>> patterns;
            for (auto itr1 = websites.begin(); itr1 != websites.end(); ++itr1) {
                for (auto itr2 = std::next(itr1); itr2 != websites.end(); ++itr2) {
                    for (auto itr3 = std::next(itr2); itr3 != websites.end(); ++itr3) {
                        patterns.emplace(itr1->second, itr2->second, itr3->second);
                    }
                }
            }

            for (const auto& pattern : patterns) {
                ++pattern2cnt[pattern];
            }
        }

        tuple<string, string, string> retPattern;
        int retCnt = 0;
        for (const auto& [pattern, cnt] : pattern2cnt) {
            if (cnt > retCnt) {
                retCnt = cnt;
                retPattern = pattern;
            }
            else if (cnt == retCnt) {
                retPattern = std::min(retPattern, pattern);
            }
        }

        const auto& [website1, website2, website3] = retPattern;
        return {website1, website2, website3};
    }
};

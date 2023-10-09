class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> m1;
        for (char c : word) {
            ++m1[c];
        }

        map<int, int> m2;
        for (const auto& [_, cnt] : m1) {
            ++m2[cnt];
        }

        if (m2.size() > 2) {
            return false;
        }

        auto it1 = m2.begin();
        auto it2 = std::next(m2.begin());

        if (m2.size() == 1) {
            if (m1.size() == 1 || it1->first == 1) {
                return true;
            }
            return false;
        }

        if (it1->first == 1 && it1->second == 1) {
            return true;
        }
        if (it1->first + 1 == it2->first && it2->second == 1) {
            return true;
        }

        return false;
    }
};

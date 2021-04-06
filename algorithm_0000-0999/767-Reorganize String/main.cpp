class Solution {
public:
    string reorganizeString_Heap(string& s) {
        typedef pair<char, int> CharCount;
        auto comp = [](const CharCount& cc1, const CharCount& cc2) {
            return (cc1.second < cc2.second);
        };
        priority_queue<CharCount, vector<CharCount>, decltype(comp)> pq(comp); { // max_heap
            unordered_map<char, int> counts;
            for (char c : s) {
                ++counts[c];
            }

            for (const auto& p : counts) {
                pq.push(p);
            }
        }

        s.assign(s.size(), ' ');
        for (size_t index = 0; !pq.empty(); pq.pop()) {
            const CharCount& cc = pq.top();
            for (int i = 0; i < cc.second; ++i) {
                if (s.size() <= index) {
                    index = 1;
                }

                if ((0 < index && s[index - 1] == cc.first) || ((index + 1) < s.size() && s[index + 1] == cc.first)) {
                    return "";
                }
                s[index] = cc.first;

                index += 2;
            }
        }

        return s;
    }

    string reorganizeString(string s) {
        return reorganizeString_Heap(s);
    }
};
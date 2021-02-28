class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (const string& word : words) {
            ++counts[word];
        }

        typedef pair<string, int> WordCount;
        auto comp = [](const WordCount& lft, const WordCount& rht) {
            if (lft.second == rht.second) {
                return lft.first < rht.first;
            }
            else {
                return rht.second < lft.second;
            }
        };
        priority_queue<WordCount, vector<WordCount>, decltype(comp)> pq(comp);
        for (auto wordCount : counts) {
            if (pq.size() < k) {
                pq.emplace(wordCount.first, wordCount.second);
            }
            else {
                if (comp(wordCount, pq.top())) {
                    pq.pop();
                    pq.emplace(wordCount.first, wordCount.second);
                }
            }
        }

        vector<string> ans;
        while (!pq.empty()) {
            WordCount wordCount = pq.top();
            pq.pop();

            ans.push_back(wordCount.first);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
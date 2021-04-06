class Solution {
public:
    vector<string> topKFrequent_Sort(vector<string>& words, int k) {
        typedef pair<string, int> WordCount;
        vector<WordCount> arr; {
            unordered_map<string, int> counts;
            for (const string& word : words) {
                ++counts[word];
            }
            arr.assign(counts.begin(), counts.end());
        }

        auto comp = [](const WordCount& nc1, const WordCount& nc2) {
            if (nc1.second == nc2.second) {
                return (nc2.first > nc1.first);
            }
            else {
                return (nc1.second > nc2.second);
            }
        };
        sort(arr.begin(), arr.end(), comp);

        vector<string> ret(k);
        for (size_t i = 0; i < k; ++i) {
            ret[i] = arr[i].first;
        }
        return ret;
    }

    vector<string> topKFrequent_Heap(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (const string& word : words) {
            ++counts[word];
        }

        typedef pair<string, int> WordCount;
        auto comp = [](const WordCount& nc1, const WordCount& nc2) {
            if (nc1.second == nc2.second) {
                return (nc1.first < nc2.first);
            }
            else {
                return (nc1.second > nc2.second);
            }
        };
        priority_queue<WordCount, vector<WordCount>, decltype(comp)> pq(comp); // min_heap
        for (const WordCount& nc : counts) {
            if (pq.size() < k) {
                pq.push(nc);
            }
            else if (comp(nc, pq.top())) {
                pq.pop();
                pq.push(nc);
            }
        }

        vector<string> ret(pq.size());
        for (size_t i = pq.size(); 0 < i--; pq.pop()) {
            ret[i] = pq.top().first;
        }
        return ret;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        // Assume we have N <word, count>

        // Sort
        // Time: O(NlogN), Space: O(logN) <- implicit stack size
        //return topKFrequent_Sort(words, k);

        // Heap
        // Time: O(NlogK), Space: O(K)
        return topKFrequent_Heap(words, k);
    }
};
class Solution {
public:
    string frequencySort_SimpleSort(string s) {
        vector<size_t> counts(128, 0);
        for (char c : s) {
            ++counts[c];
        }

        auto comp = [&](char c1, char c2) {
            if (counts[c1] == counts[c2]) {
                return c1 < c2;
            }
            else {
                return (counts[c1] > counts[c2]);
            }
        };
        sort(s.begin(), s.end(), comp);

        return s;
    }

    string frequencySort_BucketSort(string s) {
        vector<size_t> counts(128, 0);
        for (char c : s) {
            ++counts[c];
        }

        vector<vector<char>> buckets;
        for (char c = 0; c < counts.size(); ++c) {
            if (counts[c] == 0) {
                continue;
            }

            if (buckets.size() <= counts[c]) {
                buckets.resize(counts[c] + 1);
            }
            buckets[counts[c]].push_back(c);
        }

        s.clear();
        for (size_t i = buckets.size(); 0 < i--;) {
            for (char c : buckets[i]) {
                s.append(i, c);
            }
        }
        return s;
    }

    string frequencySort_Heap(string s) {
        unordered_map<char, size_t> counts;
        for (char c : s) {
            ++counts[c];
        }

        auto comp = [&](const pair<char, size_t>& p1, const pair<char, size_t>& p2) {
            return (p1.second < p2.second);
        };
        priority_queue<pair<char, size_t>, vector<pair<char, size_t>>, decltype(comp)> pq(comp); // max_heap
        for (const pair<char, size_t>& p : counts) {
            pq.push(p);
        }

        s.clear();
        for (; !pq.empty(); pq.pop()) {
            const pair<char, size_t>& p = pq.top();
            s.append(p.second, p.first);
        }
        return s;
    }

    string frequencySort(string s) {
        //return frequencySort_SimpleSort(s);
        //return frequencySort_BucketSort(s);
        return frequencySort_Heap(s);
    }
};